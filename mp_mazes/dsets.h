/* Your code here! */
#pragma once

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class DisjointSets {

public:
	void addelements(int num);

	int find(int elem);

	void setunion(int a, int b);

	int size(int elem);

private:

	vector<int> table_;

};

