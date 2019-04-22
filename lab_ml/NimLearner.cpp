/**
 * @file NimLearner.cpp
 * CS 225: Data Structures
 */

#include "NimLearner.h"
#include <ctime>
#include <boost/lexical_cast.hpp>// for lexical_cast()


/**
 * Constructor to create a game of Nim with `startingTokens` starting tokens.
 *
 * This function creates a graph, `g_` representing all of the states of a
 * game of Nim with vertex labels "p#-X", where:
 * - # is the current player's turn; p1 for Player 1, p2 for Player2
 * - X is the tokens remaining at the start of a player's turn
 *
 * For example:
 *   "p1-4" is Player 1's turn with four (4) tokens remaining
 *   "p2-8" is Player 2's turn with eight (8) tokens remaining
 *
 * All legal moves between states are created as edges with initial weights
 * of 0.
 *
 * @param startingTokens The number of starting tokens in the game of Nim.
 */
NimLearner::NimLearner(unsigned startingTokens) : g_(true, true) {
    /* Your code goes here! */
    for(int i = startingTokens; i >= 0; i--){
    g_.insertVertex("p1-"+to_string(i));
    g_.insertVertex("p2-"+to_string(i));
}
  this->startingVertex_ = "p1-"+to_string(startingTokens);
  for(int i = startingTokens; i >= 2; i--){
      g_.insertEdge("p1-"+to_string(i),"p2-"+to_string(i-1));
      g_.setEdgeWeight("p1-"+to_string(i),"p2-"+to_string(i-1),0);
      g_.setEdgeLabel("p1-"+to_string(i),"p2-"+to_string(i-1),"p1-"+to_string(i)+"T"+"p2-"+to_string(i-1));

      g_.insertEdge("p2-"+to_string(i),"p1-"+to_string(i-1));
      g_.setEdgeWeight("p2-"+to_string(i),"p1-"+to_string(i-1),0);
      g_.setEdgeLabel("p2-"+to_string(i),"p1-"+to_string(i-1),"p2-"+to_string(i)+"T"+"p1-"+to_string(i-1));

      g_.insertEdge("p1-"+to_string(i),"p2-"+to_string(i-2));
      g_.setEdgeWeight("p1-"+to_string(i),"p2-"+to_string(i-2),0);
      g_.setEdgeLabel("p1-"+to_string(i),"p2-"+to_string(i-2),"p1-"+to_string(i)+"T"+"p2-"+to_string(i-2));

      g_.insertEdge("p2-"+to_string(i),"p1-"+to_string(i-2));
      g_.setEdgeWeight("p2-"+to_string(i),"p1-"+to_string(i-2),0);
      g_.setEdgeLabel("p2-"+to_string(i),"p1-"+to_string(i-2),"p2-"+to_string(i)+"T"+"p1-"+to_string(i-2));
    }
    g_.insertEdge("p1-1","p2-0");
    g_.setEdgeWeight("p1-1","p2-0",0);
    g_.insertEdge("p2-1","p1-0");
    g_.setEdgeWeight("p2-1","p1-0",0);
      g_.setEdgeLabel("p1-1","p2-0","p1-1Tp2-0");
      g_.setEdgeLabel("p2-1","p1-0","p2-1Tp1-0");
  }


/**
 * Plays a random game of Nim, returning the path through the state graph
 * as a vector of `Edge` classes.  The `origin` of the first `Edge` must be
 * the vertex with the label "p1-#", where # is the number of starting
 * tokens.  (For example, in a 10 token game, result[0].origin must be the
 * vertex "p1-10".)
 *
 * @returns A random path through the state space graph.
 */
std::vector<Edge> NimLearner::playRandomGame() const {
  vector<Edge> path;
 /* Your code goes here! */
 int randomStep = rand()%2 + 1;
 std::string str="";
 for(size_t i = 3; i < startingVertex_.length(); i++){
   str += startingVertex_[i];
 }
 int startingTokens = boost::lexical_cast<int>(str);
 if(startingTokens == 1){
   path.push_back(g_.getEdge("p1-1","p2-0"));
   return path;
 }
 startingTokens -= randomStep;
 path.push_back(g_.getEdge(startingVertex_,"p2-"+to_string(startingTokens)));
 if(startingTokens == 0){
   return path;
 }
  bool checkLastPlayer = false;

 while(startingTokens > 2){
   checkLastPlayer = false;
   randomStep = rand()%2 + 1;
   path.push_back(g_.getEdge("p2-"+to_string(startingTokens),"p1-"+to_string(startingTokens-randomStep)));
   startingTokens -= randomStep;
   if(startingTokens == 1 || startingTokens == 2){
     checkLastPlayer = true;
     break;
   }
   randomStep = rand()%2 + 1;
   path.push_back(g_.getEdge("p1-"+to_string(startingTokens),"p2-"+to_string(startingTokens-randomStep)));
   startingTokens -= randomStep;
 }

 if(startingTokens == 1){
 if(checkLastPlayer){
    path.push_back(g_.getEdge("p1-1","p2-0"));
  } else {
    path.push_back(g_.getEdge("p2-1","p1-0"));
  }
} else {
  randomStep = rand()%2+1;
  if(randomStep == 2){
    if(checkLastPlayer){
       path.push_back(g_.getEdge("p1-2","p2-0"));
     } else {
       path.push_back(g_.getEdge("p2-2","p1-0"));
     }
  } else {
    if(checkLastPlayer){
      path.push_back(g_.getEdge("p1-2","p2-1"));
      path.push_back(g_.getEdge("p2-1","p1-0"));
    } else {
      path.push_back(g_.getEdge("p2-2","p1-1"));
      path.push_back(g_.getEdge("p1-1","p2-0"));
    }
  }
}

  return path;
}

/*
 * Updates the edge weights on the graph based on a path through the state
 * tree.
 *
 * If the `path` has Player 1 winning (eg: the last vertex in the path goes
 * to Player 2 with no tokens remaining, or "p2-0", meaning that Player 1
 * took the last token), then all choices made by Player 1 (edges where
 * Player 1 is the source vertex) are rewarded by increasing the edge weight
 * by 1 and all choices made by Player 2 are punished by changing the edge
 * weight by -1.
 *
 * Likewise, if the `path` has Player 2 winning, Player 2 choices are
 * rewarded and Player 1 choices are punished.
 *
 * @param path A path through the a game of Nim to learn.
 */
void NimLearner::updateEdgeWeights(const std::vector<Edge> & path) {
 /* Your code goes here! */
 std::string LastPath = path[path.size()-1].getLabel();
 std::string oneBeforelastplayer = "";
 oneBeforelastplayer += LastPath[0];
 oneBeforelastplayer +=LastPath[1];
for(size_t i = 0; i < path.size(); i++){
  std::string curr = path[i].getLabel();

  std::string first = "";
  std::string second ="";
  std::string firstPlayer = "";
  firstPlayer += curr[0];
  firstPlayer += curr[1];


  size_t index = curr.find("T");
  size_t j;

  for(j = 0; j<index; j++){
    first += curr[j];
    }
    std::string secondPlayer="";
    secondPlayer += curr[j+1];
    secondPlayer += curr[j+2];
  for(j = j+1 ; j<curr.size(); j++){
    second += curr[j];
  }
  int currWeight = path[i].getWeight();

  if(oneBeforelastplayer == "p1"){      //p1 is the last;
    if(firstPlayer=="p1"){
      g_.setEdgeWeight(first,second,currWeight+1);
    }else{
      g_.setEdgeWeight(first,second,currWeight-1);
    }
  } else {                                 //p2 is the last;
    if(firstPlayer=="p2"){
      g_.setEdgeWeight(first,second,currWeight+1);
    } else{
      g_.setEdgeWeight(first,second,currWeight-1);
    }
}
}

}

/**
 * Label the edges as "WIN" or "LOSE" based on a threshold.
 */
void NimLearner::labelEdgesFromThreshold(int threshold) {
  for (const Vertex & v : g_.getVertices()) {
    for (const Vertex & w : g_.getAdjacent(v)) {
      int weight = g_.getEdgeWeight(v, w);

      // Label all edges with positve weights as "WINPATH"
      if (weight > threshold)           { g_.setEdgeLabel(v, w, "WIN"); }
      else if (weight < -1 * threshold) { g_.setEdgeLabel(v, w, "LOSE"); }
    }
  }
}

/**
 * Returns a constant reference to the state space graph.
 *
 * @returns A constant reference to the state space graph.
 */
const Graph & NimLearner::getGraph() const {
  return g_;
}
