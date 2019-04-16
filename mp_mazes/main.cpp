#include <iostream>
#include "dsets.h"
#include "maze.h"
#include "cs225/PNG.h"

using namespace std;

int main()
{
    // Write your own main here
    cout << "Add your own tests here! Modify main.cpp" << endl;

    SquareMaze maze;
    maze.makeMaze(10,10);
    vector<int> path = maze.solveMaze();

    // for(int x : path){
    //     std::cout<<x<<" ";
    // }
    // std::cout<<std::endl;

    cs225::PNG* unsolved = maze.drawMaze();
    unsolved->writeToFile("TEST.png");

    cs225::PNG* solved = maze.drawMazeWithSolution();
    solved->writeToFile("TESTSOL.png");



    return 0;
}
