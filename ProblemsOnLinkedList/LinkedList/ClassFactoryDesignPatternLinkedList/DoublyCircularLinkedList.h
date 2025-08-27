#include"ILinkedList.h"
#include "Helper.h"

class DoublyCircularLinkedList:public ILinkedList
{
private:

	Node2* first;
	Node2* last;
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
