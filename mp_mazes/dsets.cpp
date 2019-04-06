/* Your code here! */
#include "dsets.h"


void DisjointSets::addelements(int num){
	//add an unconnected node at the end of the vector
	if(table_.empty()){ //intial case
    	
    	if(num==0){
    		table_.push_back(-1);
    		return;
    	}

    	for(int i=table_.size();i<=num;i++){
    		table_.push_back(-1);
    	}
    	return;
    }

    
    for(int i=0;i<=num;i++){
    		table_.push_back(-1);
    	}
}

int DisjointSets::find(int elem){
	if(table_[elem] < 0){	//if entry is -1 we are at representative element
		return elem;	//return i since it is the root idx
	}
	else {
		int root = find(table_[elem]);	//setting up unwinding recursion to point each child to its parent
		table_[elem] = root;
		return root;
	}
}

void DisjointSets::setunion(int a, int b){
	int root1 = find(a);
	int root2 = find(b);
	int newSize = table_[root1] + table_[root2];

	if(a < b){
		table_[root2] = a;
		table_[root1] = newSize;
	}

	else {
		table_[root1] = b;
		table_[root2] = newSize; 
	}

}

int DisjointSets::size(int elem){
	return (int) abs(table_[find(elem)]);
}