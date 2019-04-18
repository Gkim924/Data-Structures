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
    maze.makeMaze(50,50);
    

    cs225::PNG* unsolved = maze.drawCreativeMaze();
    unsolved->writeToFile("creative.png");

    // cs225::PNG* solved = maze.drawMazeWithSolution();
    // solved->writeToFile("TESTSOL.png");



    return 0;
}
