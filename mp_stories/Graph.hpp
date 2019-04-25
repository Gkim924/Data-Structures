#include "Graph.h"
#include "Edge.h"
#include "Vertex.h"

#include <string>
#include <iostream>

/**
* @return The number of vertices in the Graph
*/
template <class V, class E>
unsigned int Graph<V,E>::numVertices() const {
  // TODO: Part 2
  
  return vertexMap.size();

  //return 0;
}


/**
* The degree of the vertex. For directed: Sum of in-degree and out-degree
* @return Returns the degree of a given vertex.
* @param v Given vertex to return degree.
*/
template <class V, class E>
unsigned int Graph<V,E>::degree(const V & v) const {
  // TODO: Part 2

  std::list<std::reference_wrapper<E>> edges = incidentEdges(v.key());


  return edges.size();
  // std::list<edgeListIter> v1_list = adjList.at(v.key());

  // return v1_list.size();
  //return adjList.at(v.key()).size();

}


/**
* Inserts a Vertex into the Graph.
* @param key The key of the Vertex to insert
* @return The inserted Vertex
*/
template <class V, class E>
V & Graph<V,E>::insertVertex(std::string key) {
  // TODO: Part 2
  V & v = *(new V(key));

  //insert into vertex map
  std::pair<std::string, V_byRef> v_pair(key,v);
  vertexMap.insert(v_pair);

  //insert into adj list
  std::list<edgeListIter> list;
  std::pair<std::string, std::list<edgeListIter>> adj_pair(key,list);

  adjList.insert(adj_pair);

  return v;

}


/**
* Removes a given Vertex
* @param v The Vertex to remove
*/
template <class V, class E>
void Graph<V,E>::removeVertex(const std::string & key) {
  // TODO: Part 2

  typename std::list<E_byRef>::iterator it;

  for(it=edgeList.begin();it!=edgeList.end();){
    if(it->get().source().key() == key || it->get().dest().key() == key){
      removeEdge(it);
      edgeList.erase(it);
    }
    ++it;
  }
  

  

  //erase entry from vertex max
  vertexMap.erase(vertexMap.find(key));

  //erase corresponding adj list
  adjList.erase(adjList.find(key));

  //std::cout<<"edge list size"<<edgeList.size()<<std::endl;

}


/**
* Inserts an Edge into the Graph.
* @param v1 The source Vertex
* @param v2 The destination Vertex
* @return The inserted Edge
*/
template <class V, class E>
E & Graph<V,E>::insertEdge(const V & v1, const V & v2) {
  // TODO: Part 2
  E & e = *(new E(v1, v2));

  std::list<edgeListIter> v1_list = adjList[v1.key()];
  
  typename std::list<E_byRef>::iterator it1 = edgeList.insert(edgeList.begin(),e);
  
  v1_list.push_front(it1);
  //std::cout<<"V1listsize:"<<v1_list.size()<<std::endl;

  std::list<edgeListIter> v2_list = adjList[v2.key()];
  
  v2_list.push_front(it1);
  //std::cout<<"V2listsize:"<<v2_list.size()<<std::endl;

  return e;

}


/**
* Removes an Edge from the Graph. Consider both the undirected and directed cases.
* min(degree(key1), degree(key2))
* @param key1 The key of the source Vertex
* @param key2 The key of the destination Vertex
*/
template <class V, class E>
void Graph<V,E>::removeEdge(const std::string key1, const std::string key2) {  
  // TODO: Part 2

  typename std::list<E_byRef>::iterator it;

  for(it=edgeList.begin();it!=edgeList.end();){
    if(it->get().source().key() == key1 && it->get().dest().key() == key2){
      removeEdge(it);
      edgeList.erase(it);
      break;
    }
    ++it;
  }

  for(it=edgeList.begin();it!=edgeList.end();){
    if(it->get().source().key() == key2 && it->get().dest().key() == key1){
      removeEdge(it);
      edgeList.erase(it);
      break;
    }
    ++it;
  }

}


/**
* Removes an Edge from the Graph given by the location of the given iterator into the edge list.
* @param it An iterator at the location of the Edge that
* you would like to remove
*/
template <class V, class E>
void Graph<V,E>::removeEdge(const edgeListIter & it) {
  // TODO: Part 2

  if(adjList.count(it->get().source().key())>0){
    std::list<edgeListIter> v1_list = adjList[it->get().source().key()];
    //std::cout<<"Remove top"<<std::endl;
    v1_list.remove(it);
  }
  
  if(adjList.count(it->get().dest().key())>0){
    std::list<edgeListIter> v2_list = adjList[it->get().dest().key()];
    //std::cout<<"Remove down"<<std::endl;
    v2_list.remove(it);
  }
  
}


/**
* Return the list of incident edges from a given vertex.
* For the directed case, consider all edges that has the vertex as either a source or destination.
* @param key The key of the given vertex
* @return The list edges (by reference) that are adjacent to the given vertex
*/
template <class V, class E>  
const std::list<std::reference_wrapper<E>> Graph<V,E>::incidentEdges(const std::string key) const {
  // TODO: Part 2
  std::list<std::reference_wrapper<E>> edges;

  //std::list<edgeListIter> list = adjList.at(key);

  for(E_byRef e : edgeList){
    if(key == e.get().source().key() || key == e.get().dest().key()){
      edges.push_back(e);
    }
  }

  return edges;
}


/**
* Return whether the two vertices are adjacent to one another. Consider both the undirected and directed cases.
* When the graph is directed, v1 and v2 are only adjacent if there is an edge from v1 to v2.
* @param key1 The key of the source Vertex
* @param key2 The key of the destination Vertex
* @return True if v1 is adjacent to v2, False otherwise
*/
template <class V, class E>
bool Graph<V,E>::isAdjacent(const std::string key1, const std::string key2) const {
  // TODO: Part 2

  std::list<std::reference_wrapper<E>> edge1 = incidentEdges(key1);
  for(std::reference_wrapper<E> i : edge1){
    if(i.get().dest().key() == key2){
      return true;
    }
  }

  return false;
}
