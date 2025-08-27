#include "ILinkedList.h"
#include "Helper.h"

class SignlyLinearLinkedList : public ILinkedList
{
private:
    Node1* first;
    int iSize;

public:
    SignlyLinearLinkedList();
    ~SignlyLinearLinkedList();

    void insertAtFirst(int data);
    void insertAtLast(int data);
    void insertAtPos(int data, int pos);

    void deleteAtFirst();
    void deleteAtLast();
    void deleteAtPos(int pos);

    void display();
    int count();
};
