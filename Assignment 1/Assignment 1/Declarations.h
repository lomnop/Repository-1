#pragma once
#include <string>
extern int searchnum;


class Node
{
public:

	int data;
	Node(int Data);
	struct Node* next;
	struct Node* prev;
};



class DoublyLinkedList
{
public:
	struct Node* head;
	struct Node* tail;
	int Size;
	DoublyLinkedList();

	bool add(Node* new_node, int pos);
	bool remove(int pos);
	bool replace(Node* Old, Node* New);
	int search(int data);
	Node* nodeAt(int pos);
	std::string display_forward();
	std::string display_backward();
	int size();
};


