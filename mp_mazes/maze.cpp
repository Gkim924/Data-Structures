/* Your code here! */
#include "maze.h"
#include "dsets.h"
#include "cs225/PNG.h"
#include <map>
#include <queue>

using namespace cs225;
using namespace std;
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
  if(dir == 3){ //right
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
    if(dir == 1){ //down
      if(exists){
        downWalls[x+y*width] = true;
      } else {
        downWalls[x+y*width] = false;
      }
    }
}
}
std::vector<int> SquareMaze::solveMaze(){
  vector<int> lastRows;

    map<int, int> steps;
    vector<bool> visited;
    for(int i = 0; i < width*height; i++) visited.push_back(false);

    queue<int> q;
    q.push(0);
    visited[0] = true;

    while(!q.empty()) {
      int v = q.front();
      q.pop();
      int x = v % width;
      int y = v / width;
      if (y == height - 1) {
        lastRows.push_back(v);
        // if (lastRows.size() == (unsigned) width) break;
      }

      if (canTravel(x, y, 0) && !visited[v + 1]) {
        steps[v + 1] = v;
        visited[v + 1] = true;
        q.push(v + 1);
      }
      if (canTravel(x, y, 1) && !visited[v + width]) {
        steps[v + width] = v;
        visited[v + width] = true;
        q.push(v + width);
      }
      if (canTravel(x, y, 2) && !visited[v - 1]) {
        steps[v - 1] = v;
        visited[v - 1] = true;
        q.push(v - 1);
      }
      if (canTravel(x, y, 3) && !visited[v - width]) {
        steps[v - width] = v;
        visited[v - width] = true;
        q.push(v - width);
      }
    }

    vector<int> dirs;
    int i;
    for(i = lastRows.size() -1 ; i > 0; i-- ) {
    	if(lastRows[i] != lastRows[i-1]) {
    		break;
    	}
    }

    int start = lastRows[i];

// cout<<"last"<<last<<endl;
    while (start != 0) {
      int former = steps[start];
// cout<<former<<endl;
      if (start == former + 1) dirs.push_back(0);
      else if (start == former - 1) dirs.push_back(2);
      else if (start == former + width) dirs.push_back(1);
      else if (start == former - width) dirs.push_back(3);
      start = former;
    }
    std::reverse(dirs.begin(),dirs.end());
// cout<<"size: "<<dirs.size()<<endl;
    return dirs;
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
      for(int k = 0; k<10; k++){
        HSLAPixel &p = unsolved->getPixel(x,y);
        p.h = 0;
        p.s = 1;
        p.l = 0.5;
        p.a = 1;
        x++;
      }
      xMaze++;
    }
    if(solution[i] == 1){
      for(int k = 0; k<10; k++){
        HSLAPixel &p = unsolved->getPixel(x,y);
        p.h = 0;
        p.s = 1;
        p.l = 0.5;
        p.a = 1;
        y++;
      }
      yMaze++;
    }
    if(solution[i] == 2){
    for(int k = 0; k<10; k++){
      HSLAPixel &p = unsolved->getPixel(x,y);
      p.h = 0;
      p.s = 1;
      p.l = 0.5;
      p.a = 1;
      x--;
    }
    xMaze--;
    }
    if(solution[i] == 3){
      for(int k = 0; k<10; k++){
        HSLAPixel &p = unsolved->getPixel(x,y);
        p.h = 0;
        p.s = 1;
        p.l = 0.5;
        p.a = 1;
        y--;
      }
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

