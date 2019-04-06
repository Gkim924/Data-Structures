#include <iostream>
#include "dsets.h"
#include "maze.h"
#include "cs225/PNG.h"

using namespace std;

int main()
{
    // Write your own main here
    cout << "Add your own tests here! Modify main.cpp" << endl;

    std::vector<int> data;
    for(int i=0;i<5;i++){
    	data.push_back(i);
    }

    for(int x : data){
    	cout<<x<<" ";
    }




    return 0;
}
