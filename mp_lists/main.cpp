#include "List.h"
#include <iostream>

int main() {

	std::cout << "making new list" << std::endl;

	List<int> first;
	List<int> second;
	List<int> third;

	third.insertFront(9);
	third.insertFront(2);
	third.insertFront(7);
	third.insertFront(3);
	third.insertFront(4);
	third.insertFront(8);
	third.insertFront(5);
	third.insertFront(1);
	third.insertFront(6);
	
	//first.insertFront(6);
	//first.insertFront(4);
	//first.insertFront(3);
	first.insertFront(8);

	
	second.insertFront(7);
	second.insertFront(5);
	second.insertFront(2);
	second.insertFront(1);

	
	
	
	std::cout << "first list size after additions: " << first.size() << std::endl;
	//std::cout << "second list size after additions: " << second.size() << std::endl;
	//std::cout << "third list size after additions: " << third.size() << std::endl;
	first.print();
	std::cout << std::endl;
	first.reverse();
	first.print();
	std::cout << std::endl;
	//second.print();
	//std::cout << std::endl;

	//first.mergeWith(second);
	//first.print();
	//std::cout << std::endl;
	//second.print();
	//std::cout << std::endl;

	//third.print();
	//std::cout << std::endl;
	//third.sort();
	//third.print();
	//std::cout << std::endl;






	//first.waterfall();
	//first.print();
	//std::cout << std::endl;
	//first.reverse();
	//first.print();
	//std::cout << std::endl;
	//first.reverseNth(3);
	//first.print();
	//std::cout << std::endl;
	// second = first.split(0);
	// second.print();
	// std::cout << std::endl;
	// first.print();
	// std::cout << std::endl;


	// first.insertBack(1);
	// first.insertBack(2);
	// first.insertBack(3);
	// first.insertBack(4);

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
