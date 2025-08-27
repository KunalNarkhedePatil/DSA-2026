#include "DoublyCircularLinkedList.h"

DoublyCircularLinkedList::DoublyCircularLinkedList()
{
	first = NULL;
	last = NULL;
	iSize = 0;
}
DoublyCircularLinkedList::~DoublyCircularLinkedList()
{
	while (iSize > 0)
	{
		deleteAtFirst();
	}
}

void DoublyCircularLinkedList::insertAtFirst(int value)
{
	Node2* newn = new Node2(value);

	if (nullptr == first && nullptr == last)
	{
		first = newn;
		last = newn;
		first->next = first;
		first->prev = first;
	}
	else
	{
		newn->next = first;
		first->prev = newn;
		newn->prev = last;
		first = newn;
		last->next = first;
	}
	iSize++;
}

void DoublyCircularLinkedList::insertAtLast(int value)
{
	Node2* newn = new Node2(value);

	if (nullptr == first && nullptr == last)
	{
		first = newn;
		last = newn;

		first->next = first;
		first->prev = first;
	}
	else
	{
		last->next = newn;
		newn->prev = last;
		newn->next = first;
		last = newn;
		first->prev = last;
	}
	iSize++;
}

void DoublyCircularLinkedList::insertAtPos(int value, int pos)
{
	if (pos<1 || pos>iSize)
	{
		std::cout << "Invalid position" << std::endl;
		return;
	}

	if (pos == 1)
	{
		insertAtFirst(value);
	}
	else if (pos == iSize + 1)
	{
		insertAtLast(value);
	}
	else
	{
		Node2* newn = new Node2(value);
		Node2* temp = first;
		for (int i = 1;i < pos - 1;i++)
		{
			temp = temp->next;
		}

		newn->next = temp->next;
		newn->next->prev = newn;

		temp->next = newn;
		newn->prev = temp;
		iSize++;
	}
}

void DoublyCircularLinkedList::deleteAtFirst()
{
	if (nullptr == first && nullptr == last)
	{
		std::cout << "Linked List is empty..." << std::endl;
		return;
	}

	if (first == last)
	{
		delete first;
		first = nullptr;
		last = nullptr;
	}
	else
	{
		Node2* temp = first;
		first = first->next;
		delete temp;
		temp = nullptr;
		first->prev = last;
		last->next = first;
	}
	iSize--;
}

void DoublyCircularLinkedList::deleteAtLast()
{
	if (nullptr == first && nullptr == last)
	{
		std::cout << "Linked List is empty..." << std::endl;
		return;
	}

	if (first == last)
	{
		delete first;
		first = nullptr;
		last = nullptr;
	}
	else {

		Node2* temp = last;
		last = last->prev;

		delete temp;
		temp = nullptr;

		last->next = first;
		first->prev = last;

	}
	iSize--;
}

void DoublyCircularLinkedList::deleteAtPos(int pos)
{
	if (pos<1 || pos>iSize)
	{
		std::cout << "Invalid position" << std::endl;
		return;
	}

	if (pos == 1)
	{
		deleteAtFirst();
	}
	else  if (pos == iSize)
	{
		deleteAtLast();
	}
	else
	{
		Node2* temp = first;

		for (int i = 1;i < pos - 1;i++)
		{
			temp = temp->next;
		}

		Node2* targated = temp->next;

		temp->next = targated->next;
		temp->next->prev = temp;
		delete targated;
		targated = nullptr;
		iSize--;
	}

}

void DoublyCircularLinkedList::display()
{

	if (nullptr == first)
	{
		std::cout << "Linked List is Empty..." << std::endl;
		return;
	}
	Node2* temp = first;


	do
	{
		std::cout << temp->data;
		temp = temp->next;
		if (temp != first)
		{
			std::cout << "->";
		}

	} while (temp != first);
	std::cout << std::endl;
}

int DoublyCircularLinkedList::count()
{
	return iSize;
}

