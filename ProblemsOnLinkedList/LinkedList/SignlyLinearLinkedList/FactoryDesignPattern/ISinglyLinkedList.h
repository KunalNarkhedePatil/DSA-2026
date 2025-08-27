#ifndef ISINGLYLINKEDLIST_H
#define ISINGLYLINKEDLIST_H

#include <iostream>

// Interface (Abstract Class)
class ISinglyLinkedList
{
public:
    virtual void insertAtFirst(int data) = 0;
    virtual void insertAtLast(int data) = 0;
    virtual void insertAtPos(int data, int pos) = 0;

    virtual void deleteAtFirst() = 0;
    virtual void deleteAtLast() = 0;
    virtual void deleteAtPos(int pos) = 0;

    virtual void display() = 0;
    virtual int count() = 0;

    static ISinglyLinkedList* getInstance(); // Factory Method
    virtual ~ISinglyLinkedList() = default;  // Virtual destructor
};

#endif
