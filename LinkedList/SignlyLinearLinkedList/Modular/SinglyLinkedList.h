#include<iostream>

class Node
{
    private:

    int data;
    Node* next;

    Node(int value)
    {
        this->data=value;
        this->next=NULL;
    }

    friend class SinglyLinkedList;
};

class SinglyLinkedList
{
    private:

    Node* first;

    int iSize;

    public:
SinglyLinkedList();
    void insertAtFirst(int data);
    void insertAtLast(int data);
    void  insertAtPos(int data,int pos);
    void deleteAtFirst();
    void deleteAtLast();
    void deleteAtPos(int pos);

    void display();
    int count();
    void clear();
    ~SinglyLinkedList();
};