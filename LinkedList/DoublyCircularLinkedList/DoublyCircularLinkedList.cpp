#include<iostream>

class Node
{
private:
	int data;
	Node* prev;
	Node* next;

public:

	Node(int data)
	{
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}

	friend class DoublyCircularLinkedList;
};
class DoublyCircularLinkedList
{
private:

	Node* first;
	Node* last;
	int iSize;

public:

	DoublyCircularLinkedList();
	~DoublyCircularLinkedList();

	void insertAtFirst(int data);
	void insertAtLast(int data);
	void insertAtPos(int data, int pos);

	void deleteAtFirst();
	void deleteAtLast();
	void deleteAtPos(int pos);

	void display();
	int count();
};

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
	Node* newn = new Node(value);

	if (NULL == first && NULL == last)
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
	Node* newn = new Node(value);

	if (NULL == first && NULL == last)
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
		Node* newn = new Node(value);
		Node* temp = first;
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
	if (NULL == first && NULL == last)
	{
		std::cout << "Linked List is empty..." << std::endl;
		return;
	}

	if (first == last)
	{
		delete first;
		first = NULL;
		last = NULL;
	}
	else
	{
		Node* temp = first;
		first = first->next;
		delete temp;
		temp = NULL;
		first->prev = last;
		last->next = first;
	}
	iSize--;
}

void DoublyCircularLinkedList::deleteAtLast()
{
	if (NULL == first && NULL == last)
	{
		std::cout << "Linked List is empty..." << std::endl;
		return;
	}

	if (first == last)
	{
		delete first;
		first = NULL;
		last = NULL;
	}
	else {

		Node* temp = last;
		last = last->prev;

		delete temp;
		temp = NULL;

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
		Node* temp = first;

		for (int i = 1;i < pos - 1;i++)
		{
			temp = temp->next;
		}

		Node* targated = temp->next;

		temp->next = targated->next;
		temp->next->prev = temp;
		delete targated;
		targated = NULL;
		iSize--;
	}

}

void DoublyCircularLinkedList::display()
{

	if (NULL == first)
	{
		std::cout << "Linked List is Empty..." << std::endl;
		return;
	}
	Node* temp = first;


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

int main()
{

	DoublyCircularLinkedList dobj;

	dobj.insertAtFirst(50);
	dobj.insertAtFirst(40);
	dobj.insertAtFirst(30);
	dobj.insertAtFirst(20);
	dobj.insertAtFirst(10);

	dobj.insertAtLast(60);

	dobj.insertAtPos(25, 3);

	dobj.deleteAtFirst();

	dobj.deleteAtLast();

	dobj.deleteAtPos(2);

	dobj.display();

	std::cout << "Number of nodes in the linked list are:" << dobj.count() << std::endl;
	return 0;
}