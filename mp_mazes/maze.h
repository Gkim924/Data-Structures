/* Your code here! */
#include "cs225/PNG.h"

#include <vector>
#include <stack>

class SquareMaze{
public:
  SquareMaze();
  void makeMaze(int width, int height);
  bool canTravel(int x, int y, int dir) const;
  void setWall(int x, int y, int dir, bool exists);

  void _solveMaze1(int x, int y, int * last_row, std::vector<int> &path);
  bool _solveMaze2(int x, int y, int xFin, std::vector<int> &path);

  std::vector<int> solveMaze();
  cs225::PNG* drawMaze() const;
  cs225::PNG* drawMazeWithSolution();
  cs225::PNG* drawCreativeMaze() const;

private:
  int width;
  int height;
  std::vector<bool> downWalls;
  std::vector<bool> rightWalls;
};

