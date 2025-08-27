#ifndef SINGLYCIRCULARLINKEDLIST_H
#define SINGLYCIRCULARLINKEDLIST_H

#include "ISinglyCircularLinkedList.h"

class Node
{
private:
    int data;
    Node* next;
public:
    Node(int value) : data(value), next(nullptr) {}
    friend class SinglyCircularLinkedList;
};

class SinglyCircularLinkedList : public ISinglyCircularLinkedList
{
private:
    Node* first;
    Node* last;
    int iSize;

public:
    SinglyCircularLinkedList();
    ~SinglyCircularLinkedList();

    void insertAtFirst(int data) override;
    void insertAtLast(int data) override;
    void insertAtPos(int data, int pos) override;

    void deleteAtFirst() override;
    void deleteAtLast() override;
    void deleteAtPos(int pos) override;

    void display() override;
    int count() override;
};

#endif
