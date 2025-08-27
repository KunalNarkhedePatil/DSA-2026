#include<iostream>

class Node
{

private:
	int data;
	Node* next;


	friend class SinglyLinkedList;
public:
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

class  SinglyLinkedList
{
private:
	Node* first;
	int iSize;

public:

	SinglyLinkedList()
	{
		first = NULL;
		iSize = 0;
	}
	void insertAtFirst(int data)
	{
		Node* newn = new Node(data);

		if (first == NULL)
		{
			first = newn;
		}
		else
		{
			newn->next = first;
			first = newn;
		}

		iSize++;
	}
	void insertAtLast(int data)
	{
		Node* newn = new Node(data);
		if (first == NULL)
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
		}
		iSize++;
	}
	void insertAtPos(int data, int pos)
	{
		if (pos<1 || pos>iSize + 1)
		{
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
				if (temp == NULL)
				{
					return;
				}
				temp = temp->next;
			}

			newn->next = temp->next;
			temp->next = newn;

			iSize++;

		}
	}
	//delete First

	void deleteFirst()
	{
		if (NULL == first)
		{
			std::cout << "Linked list is empty" << std::endl;
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

			delete temp;
			temp = NULL;
		}

		iSize--;
	}

	void deleteLast()
	{
		if (NULL == first)
		{
			std::cout << "Linked list is empty" << std::endl;
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

			while (temp->next->next != NULL)
			{
				temp = temp->next;
			}
			delete temp->next;
			temp->next = NULL;
		}
		iSize--;
	}

	void deleteAtPos(int pos)
	{
		if (pos<1 || pos>iSize)
		{
			std::cout << "Invalid Pos" << std::endl;
			return;
		}

		if (pos == 1)
		{
			deleteFirst();
		}
		else if (pos == iSize)
		{
			deleteLast();
		}
		else
		{
			Node* temp = first;

			for (int i = 1;i < pos - 1;i++)
			{
				temp = temp->next;
			}
			Node* targatedNode = temp->next;

			temp->next = targatedNode->next;

			delete targatedNode;
			targatedNode = NULL;
			iSize--;
		}
	}

	void Display()
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

	int getCount()
	{
		return iSize;
	}
};
int main()
{
	SinglyLinkedList sobj;

	sobj.insertAtFirst(5);
	sobj.insertAtLast(10);
	sobj.insertAtLast(20);
	sobj.insertAtLast(30);
	sobj.insertAtLast(40);

	sobj.insertAtPos(25, 3);

	sobj.deleteFirst();
	sobj.deleteLast();
	sobj.deleteAtPos(2);
	sobj.Display();

	std::cout << "Count :" << sobj.getCount() << std::endl;
	return 0;
}