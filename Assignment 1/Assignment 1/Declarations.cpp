#include "Declarations.h"

int searchnum = 0;

Node::Node(int Data)
{
	data = Data;
}

DoublyLinkedList::DoublyLinkedList()
{
	Size = -1;
	head = nullptr;
	tail = nullptr;
}



bool DoublyLinkedList::add(Node* new_node, int pos)
{

	if (new_node != nullptr)
	{
		if (pos<=Size+1 && pos>-1 && new_node->data > -1)
		{
			Size++;

			if (pos == 0) //If head
			{
				new_node->prev = nullptr;
				if (Size == 0)
				{
					head = new_node;
					tail = new_node;
					new_node->next = nullptr;
				}
				else
				{
					head->prev = new_node;
					new_node->next = head;
					head = new_node;
				}
			}
			else if (pos == Size)//or tail
			{
				tail->next = new_node;
				new_node->prev = tail;
				tail = new_node;
				new_node->next = nullptr;
			}
			else
			{
				new_node->prev = nodeAt(pos - 1);
				new_node->next = nodeAt(pos);
				nodeAt(pos - 1)->next = new_node;
				nodeAt(pos + 1)->prev = new_node;
			}
			return(true);
		}
		else
			return(false);
	}
	else
		return(false);
	

}

Node* DoublyLinkedList::nodeAt(int pos)
{
	searchnum = 0;
	Node* temp = nullptr;
	Node* ptr = head;
	while (pos > searchnum)
	{
		if (ptr->next == NULL)
			return(NULL);
		ptr = ptr->next;
		searchnum++;
	}
	temp = ptr;
	return temp;
}

std::string DoublyLinkedList::display_forward() // iterate through list from head and add each data into a string
{
	std::string output;
	output = "";
	Node* ptr = head;
	while (ptr != nullptr)
	{

		if (ptr->data == 0)
		{
			output += "0 ";
		}
		else
		{
			output += std::to_string(ptr->data) + " ";
		}
		ptr = ptr->next;
	}

	return(output);
}

std::string DoublyLinkedList::display_backward() //// iterate through list from tail and add each data into a string
{
	std::string output;
	output = "";
	Node* ptr = tail;
	while (ptr != NULL)
	{
		if (ptr->data == 0)
		{
			output += "0 ";
		}
		else
		{
			output += std::to_string(ptr->data) + " ";
		}
		ptr = ptr->prev;
	}

	return(output);
}

bool::DoublyLinkedList::remove(int pos) 
{
	if (pos<Size + 1 && pos>-1)
	{
		if (pos == 0 && pos == Size)
		{
			free(head);
			head = NULL;
			tail = NULL;
		}
		else if (pos == 0)
		{
			nodeAt(pos + 1)->prev = head;
			head = nodeAt(pos + 1);
			free(head->prev);
			head->prev = NULL;
		}
		else if (pos == Size)
		{
			nodeAt(pos - 1)->next = NULL;
			tail = nodeAt(pos - 1);
			free(nodeAt(pos));
		}
		else
		{
			head->prev = nodeAt(pos);
			nodeAt(pos - 1)->next = nodeAt(pos + 1);
			nodeAt(pos)->prev = nodeAt(pos - 1);
			free(head->prev);
			head->prev = NULL;
		}



		Size--;

		return(true);
	}
	else
	{
		return(false);
	}

}

int DoublyLinkedList::search(int data) // iteration through head to find matching data
{
	Node* ptr = head;
	int searchpos = -1;
	while (ptr != NULL)
	{
		searchpos++;
		if (data == ptr->data)
		{
			return(searchpos);
		}
		else
		{
			ptr = ptr->next;
		}
	}
	return(-1);
}

int DoublyLinkedList::size()
{
	return(Size + 1);
}

bool DoublyLinkedList::replace(Node* Old, Node* New)
{
	
	
	if (Old!= NULL && New!=NULL && Old->prev != NULL && Old->next != NULL || Old == head && Old == tail)
	{
		if (Old == head && Old == tail)
		{
			New = head;
			New = tail;
			New->next = NULL;
			New->prev = NULL;
		}
		else if (Old == head)
		{
			Old->next->prev = New;
			New->prev = NULL;
			New->next = Old->next;
			free(Old);
			head = New;
			return(1);
		}
		else if (Old == tail)
		{
			Old->prev->next = New;
			New->next = NULL;
			New->prev = Old->prev;
			free(Old);
			tail = New;
			return(1);
		}
		else
		{
			New->next = Old->next;
			New->prev = Old->prev;
			Old->prev->next = New;
			Old->next->prev = New;
			free(Old);
			return(1);
		}
	}
	else
	{
		return(false);
	}
	

}
