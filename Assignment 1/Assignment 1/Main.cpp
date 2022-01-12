#include <iostream>
#include "Declarations.h"

int main()
{
	Node* n0 = new Node(0);
	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);
	Node* n5 = new Node(5);

	DoublyLinkedList list;

	
	std::cout << list.add(n0, 0);
	std::cout << list.add(n1, 10); //should be a false or -1 (error/invalid) 
	std::cout << list.add(nullptr, 1); //should be a false or -1 (error/invalid) 
	std::cout << list.add(n1, 1);
	std::cout << list.remove(3); //should be a false or -1 (error/invalid) ;
	std::cout << list.add(n2, 2);
	std::cout << std::endl << list.display_forward();
	std::cout << std::endl<<list.add(n3,1);
	std::cout << std::endl << list.display_forward();
	std::cout << std::endl << list.remove(2);
	std::cout << std::endl << list.display_forward();
	std::cout << std::endl << list.display_backward();
	std::cout << std::endl << list.search(n4->data); //should be a false or -1 (error/invalid)
	std::cout << std::endl << list.search(n3->data);
	std::cout << std::endl << list.replace(n3,nullptr); //should be a false or -1 (error/invalid) 
	std::cout << std::endl << list.replace(n5, n4); //should be a false or -1 (error/invalid) 
	std::cout << std::endl << list.replace(n3, n4);
	std::cout << std::endl << list.display_forward();
	std::cout << std::endl << list.size();
		return 0;
}