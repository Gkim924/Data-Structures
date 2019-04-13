/* Your code here! */
#include "cs225/PNG.h"

#include <vector>

class SquareMaze{
public:
  void makeMaze();
  void makeMaze(int width, int height);
  bool canTravel(int x, int y, int dir) const;
  void setWall(int x, int y, int dir, bool exists);
  std::vector<int> solveMaze();
  cs225::PNG* drawMaze() const;
  cs225::PNG* drawMazeWithSolution();

private:
  int width;
  int height;
  std::vector<bool> downWalls;
  std::vector<bool> rightWalls;
};

