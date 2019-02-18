#include "List.h"
#include <iostream>

int main() {

	std::cout << "making new list" << std::endl;

	List<int> first;

	std::cout << "list size: " << first.size() << std::endl;

	//***** write _destroy() and destructor

	first.insertFront(7);

	std::cout << "list size after addition: " << first.size() << std::endl;

	first.insertFront(2);

	std::cout << "list size after addition: " << first.size() << std::endl;



  return 0;
}
