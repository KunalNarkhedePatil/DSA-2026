#include "ILinkedList.h"
#include "Helper.h"

class DoublyLinearLinkedList:public ILinkedList
{
private:

	Node2* first;
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