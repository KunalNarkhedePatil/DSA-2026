#ifndef ISINGLYCIRCULARLINKEDLIST_H
#define ISINGLYCIRCULARLINKEDLIST_H

#include <iostream>

// Forward declaration
class SinglyCircularLinkedList;

// Interface (Abstract Class)
class ISinglyCircularLinkedList
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

    static ISinglyCircularLinkedList* getInstance(); // Factory Method
    static void relaseInstance(ISinglyCircularLinkedList* instance);
    virtual ~ISinglyCircularLinkedList() = default;  // Virtual destructor
};

#endif
