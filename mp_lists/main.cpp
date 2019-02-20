#include "List.h"
#include <iostream>

int main() {

	std::cout << "making new list" << std::endl;

	List<int> first;

	first.insertFront(1);
	first.insertFront(2);
	first.insertFront(3);
	first.insertFront(4);

	// first.insertBack(1);
	// first.insertBack(2);
	// first.insertBack(3);
	// first.insertBack(4);
	
	
	//std::cout << "list size after additions: " << first.size() << std::endl;

	//List<int>::ListIterator checkF = first.begin();
	//List<int>::ListIterator checkB = first.end();

	//int test = *checkF;
	

	//std::cout << "contents of end iterator: " << test << std::endl;
	//checkF++;
	//checkF++;
	//checkF--;

	//test = *checkF;
	//std::cout << "contents from iterator: " << test << std::endl;
	// checkF++;
	// test = *checkF;
	// std::cout << "contents from iterator: " << test << std::endl;
	

	// std::cout << "contents of head from iterator: " << test << std::endl;
	// std::cout << "incrementing iterator" << std::endl;
	// checkF++;
	// test = *checkF;
	// std::cout << "contents of iterator: " << test << std::endl;
	// std::cout << "decrementing iterator" << std::endl;
	// checkF--;
	// test = *checkF;
	// std::cout << "contents of iterator: " << test << std::endl;
	
  	

	

	
	



  return 0;
}
