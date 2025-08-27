#include "ILinkedList.h"
#include "Helper.h"

class SinglyCircularLinkedList : public ILinkedList
{
private:
    Node1* first;
    Node1* last;
    int iSize;

public:
    SinglyCircularLinkedList();
    ~SinglyCircularLinkedList();

    void insertAtFirst(int data);
    void insertAtLast(int data);
    void insertAtPos(int data, int pos);

    void deleteAtFirst();
    void deleteAtLast();
    void deleteAtPos(int pos);

    void display();
    int count();
};
