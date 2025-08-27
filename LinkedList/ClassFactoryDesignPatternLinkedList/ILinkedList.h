#pragma once
#include<iostream>
class ILinkedList
{
public:
    virtual ~ILinkedList() {}

    virtual void insertAtFirst(int data) = 0;
    virtual void insertAtLast(int data) = 0;
    virtual void insertAtPos(int data, int pos) = 0;

    virtual void deleteAtFirst() = 0;
    virtual void deleteAtLast() = 0;
    virtual void deleteAtPos(int pos) = 0;

    virtual void display() = 0;
    virtual int count() = 0;

    static ILinkedList* getInstance(int type);
};
