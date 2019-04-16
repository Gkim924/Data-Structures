/* Your code here! */
#include "maze.h"
#include "dsets.h"
#include "cs225/PNG.h"
#include <map>
#include <queue>

using namespace cs225;
using namespace std;

SquareMaze::SquareMaze(){

};

void SquareMaze::makeMaze(int width, int height){
  this->width = width;
  this->height = height;
  for(int i = 0; i < width*height; i++){
    downWalls.push_back(true);
    rightWalls.push_back(true);
  }
  DisjointSets disjoint;
  disjoint.addelements(width*height);
  int count = 0;
  while (count < height*width-1) {
    int randsize = rand()%(width*height);
    int x = randsize%width;
    int y = randsize/width;
    int group = rand()%(width*height);
    if(group < width*height/4){
      if(x < width-1 && disjoint.find(x+y*width) != disjoint.find(x+1+y*width) && rightWalls[x+y*width]){
        rightWalls[x+y*width] = false;
        disjoint.setunion(disjoint.find(x+y*width),disjoint.find(x+1+y*width));
        count++;
      }
    }else if(group < width*height/2){
      if(y < height-1 && disjoint.find(x+y*width)!= disjoint.find(x+(1+y)*width) && downWalls[x+y*width]){
        downWalls[x+y*width] = false;
        disjoint.setunion(disjoint.find(x+y*width),disjoint.find(x+(1+y)*width));
        count++;
    }
  } else if(group < 3*width*height/4){
    if(x < width-1 && disjoint.find(x+y*width) != disjoint.find(x+1+y*width) && rightWalls[x+y*width]){
      rightWalls[x+y*width] = false;
      disjoint.setunion(disjoint.find(x+y*width),disjoint.find(x+1+y*width));
      count++;
    }
} else {
  if(y < height-1 && disjoint.find(x+y*width)!= disjoint.find(x+(1+y)*width) && downWalls[x+y*width]){
    downWalls[x+y*width] = false;
    disjoint.setunion(disjoint.find(x+y*width),disjoint.find(x+(1+y)*width));
    count++;
}
  }
  }

}
bool SquareMaze::canTravel(int x, int y, int dir) const{
  if(dir == 0){ //right
    if(x == width-1) return false;
    if(rightWalls[x+y*width]) return false;
  }
  if(dir == 1){ //down
    if(y == height-1) return false;
    if(downWalls[x+y*width]) return false;
  }
  if(dir == 2){ //left
    if(x == 0) return false;
    if(rightWalls[(x-1)+y*width]) return false;
  }
  if(dir == 3){ //up
    if(y == 0) return false;
    if(downWalls[x+(y-1)*width]) return false;
  }
  return true;
}
void SquareMaze::setWall(int x, int y, int dir, bool exists){

  if(dir == 0){ //right
    if(exists){
      rightWalls[x+y*width] = true;
    }else {
      rightWalls[x+y*width] = false;
    }
	}
    if(dir == 1){ //down
      if(exists){
        downWalls[x+y*width] = true;
      } else {
        downWalls[x+y*width] = false;
      }
    }


}

//solve maze using DisjointSets method in stack.
std::vector<int> SquareMaze::solveMaze(){

std::stack<int> nodes;    //contains the nodes that form paths
std::stack<int> index;    //contains the nodes from prev node.
std::vector<int> visited;
std::queue<int> traverse;   //a queue that contains the current node's neighbors.
for(int i = 0; i < width*height; i++){
visited.push_back(false);
}
traverse.push(0);
index.push(-1);
while(!traverse.empty()){
nodes.push(traverse.front());

int curr = traverse.front();

int x = curr%width;
int y = curr/width;
traverse.pop();
visited[curr] = true;
if(canTravel(x,y,0) && !visited[curr+1]){
  traverse.push(curr+1);
  index.push(curr);
}
if(canTravel(x,y,1) && !visited[curr+width]){
  traverse.push(curr+width);
  index.push(curr);
}
if(canTravel(x,y,2) && !visited[curr-1]){
  traverse.push(curr-1);
  index.push(curr);
}
if(canTravel(x,y,3) && !visited[curr-width]){
  traverse.push(curr-width);
  index.push(curr);
}
}
while (nodes.top()/width != height-1) {    //pop all the nodes from stack until the top of the stack is the in the last row,
  nodes.pop();                             //which should be the furthest from the origin.
}
while(index.size() != nodes.size()){      //pop all the unnecessary index until index and nodes are the same size.
  index.pop();
}
std::vector<int> direction;    //contains the vector of directions.
while(nodes.top() != 0){
int currNode = nodes.top();
int currIndex = index.top();

if(currIndex+1 == currNode){
  direction.push_back(0);
}
if(currIndex+width == currNode){
  direction.push_back(1);
}
if(currIndex-1 == currNode){
  direction.push_back(2);
}
if(currIndex-width == currNode){
  direction.push_back(3);
}
while (nodes.top() != currIndex) {
  nodes.pop();
  index.pop();
}
}

reverse(direction.begin(),direction.end());   //reverse the vector of direction.

return direction;

}


cs225::PNG* SquareMaze::drawMaze() const{

  cs225::PNG* unsolved = new cs225::PNG(width*10+1,height*10+1);
  for(int i = 0; i < height*10+1; i++){
    HSLAPixel &p = unsolved->getPixel(0,i);
    p.l = 0;
  }
  for(int i = 0; i < width*10+1; i++){
    HSLAPixel &p = unsolved->getPixel(i,0);
    if(i == 0 || i > 9){
      p.l = 0;
    }
  }
  for(int x = 0; x < width; x++){
    for(int y = 0 ; y < height; y++){
      if(rightWalls[x+y*width]){
        for(int k = 0; k <= 10; k++){
        HSLAPixel &p = unsolved->getPixel((x+1)*10,y*10+k);
        p.l = 0;
      }
    }
    if(downWalls[x+y*width]){
      for(int k = 0; k <= 10; k++){
      HSLAPixel &p = unsolved->getPixel(x*10+k,(y+1)*10);
      p.l = 0;
    }
  }

  }
}
return unsolved;

}
cs225::PNG* SquareMaze::drawMazeWithSolution(){
  PNG* unsolved = drawMaze();
  vector<int> solution = solveMaze();
  int x = 5;
  int y = 5;
  int xMaze = 0;
  int yMaze = 0;
    for(size_t i = 0; i < solution.size(); i++){
    if(solution[i] == 0){
      for(int k = 0; k<=10; k++){
        HSLAPixel &p = unsolved->getPixel(x+k,y);
        p.h = 0;
        p.s = 1;
        p.l = 0.5;
        p.a = 1;
        //x++;
      }
      x += 10;
      xMaze++;
    }
    if(solution[i] == 1){
      for(int k = 0; k<=10; k++){
        HSLAPixel &p = unsolved->getPixel(x,y+k);
        p.h = 0;
        p.s = 1;
        p.l = 0.5;
        p.a = 1;
        //y++;
      }
      y += 10;
      yMaze++;
    }
    if(solution[i] == 2){
    for(int k = 0; k<=10; k++){
      HSLAPixel &p = unsolved->getPixel(x-k,y);
      p.h = 0;
      p.s = 1;
      p.l = 0.5;
      p.a = 1;
      //x--;
    }
    x -= 10;
    xMaze--;
    }
    if(solution[i] == 3){
      for(int k = 0; k<=10; k++){
        HSLAPixel &p = unsolved->getPixel(x,y-k);
        p.h = 0;
        p.s = 1;
        p.l = 0.5;
        p.a = 1;
        //y--;
      }
      y-=10;
      yMaze--;
    }
  }
  for(int k = 1; k<=9; k++){
    HSLAPixel &p = unsolved->getPixel(xMaze*10+k, (yMaze+1)*10);
    p.l = 1;
    p.a = 1;
  }
      return unsolved;
}

