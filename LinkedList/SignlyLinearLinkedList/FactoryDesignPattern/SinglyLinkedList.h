#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include "ISinglyLinkedList.h"

// Node class
class Node
{
private:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}

    friend class SinglyLinkedList;
};

// Implementation of ISinglyLinkedList
class SinglyLinkedList : public ISinglyLinkedList
{
private:
    Node* first;
    int iSize;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    void insertAtFirst(int data) override;
    void insertAtLast(int data) override;
    void insertAtPos(int data, int pos) override;

    void deleteAtFirst() override;
    void deleteAtLast() override;
    void deleteAtPos(int pos) override;

    void display() override;
    int count() override;
    void clear();
};

#endif
