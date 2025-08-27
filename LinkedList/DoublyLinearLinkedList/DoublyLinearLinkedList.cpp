#include<iostream>

class Node
{
private:

	int data;
	Node* next;
	Node* prev;

public:

	Node(int value)
	{
		this->data = value;
		this->next = NULL;
		this->prev = NULL;
	}

	friend class DoublyLinearLinkedList;
};
class DoublyLinearLinkedList
{
private:

	Node* first;
	int iSize;

public:

	DoublyLinearLinkedList();
	~DoublyLinearLinkedList();

	void insertAtFirst(int data);
	void insertAtLast(int data);
	void insertAtPos(int data, int pos);

	void deleteAtFirst();
	void deleteAtLast();
	void deleteAtPos(int pos);

	void display();
	int count();
};

DoublyLinearLinkedList::DoublyLinearLinkedList()
{
	this->first = NULL;
	this->iSize = 0;
}

DoublyLinearLinkedList::~DoublyLinearLinkedList()
{
	while (iSize > 0)
	{
		deleteAtFirst();
	}
}

void DoublyLinearLinkedList::insertAtFirst(int data)
{
	Node* newn = new Node(data);
	if (NULL == first)
	{
		first = newn;
	}
	else
	{
		newn->next = first;
		first->prev = newn;
		first = newn;
	}
	iSize++;
}
void DoublyLinearLinkedList::insertAtLast(int data)
{
	Node* newn = new Node(data);

	if (NULL == first)
	{
		first = newn;
	}
	else
	{
		Node* temp = first;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = newn;
		newn->prev = temp;
	}
	iSize++;
}

void DoublyLinearLinkedList::insertAtPos(int data, int pos)
{
	if (pos<1 || pos>iSize + 1)
	{
		std::cout << "Pos:" << pos << " " << "iSize:" << iSize << std::endl;
		std::cout << "Invalid Position" << std::endl;
		return;
	}

	if (pos == 1)
	{
		insertAtFirst(data);
	}
	else if (pos == iSize + 1)
	{
		insertAtLast(data);
	}
	else
	{
		Node* newn = new Node(data);

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

void DoublyLinearLinkedList::deleteAtFirst()
{
	if (NULL == first)
	{
		return;
	}
	if (NULL == first->next)
	{
		delete first;
		first = NULL;
	}
	else
	{
		Node* temp = first;

		first = first->next;
		first->prev = NULL;

		delete temp;
		temp = NULL;
	}
	iSize--;
}

void DoublyLinearLinkedList::deleteAtLast()
{
   if(NULL==first)
   {
       return;
   }
   if(NULL==first->next)
   {
	   delete first;
	   first = NULL;
   }
   else
   {
	   Node* temp = first;

	   while (temp->next->next != NULL)
	   {
		   temp = temp->next;
	   }

	   delete temp->next;
	   temp->next = NULL;
   }
   iSize--;
}

void DoublyLinearLinkedList::deleteAtPos(int pos)
{
    if(pos<1 || pos>iSize)
    {
        std::cout<<"Invalid Position"<<std::endl;
        return;
    }

    if(pos==1)
    {
        deleteAtFirst();
    }
    else if(pos==iSize)
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

void DoublyLinearLinkedList::display()
{
	Node* temp = first;

	while (temp != NULL)
	{
		std::cout << temp->data;
		if (temp->next != NULL)
		{
			std::cout << "->";
		}
		temp = temp->next;
	}
	std::cout << std::endl;
}

int DoublyLinearLinkedList::count()
{
	return iSize;
}
int main()
{
	DoublyLinearLinkedList dobj;

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

	std::cout << "Count:" << dobj.count() << std::endl;

	dobj.display();

	return 0;
}