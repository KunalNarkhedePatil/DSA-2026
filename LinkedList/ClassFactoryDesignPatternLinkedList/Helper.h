#pragma once
#ifndef _HELPER_H
#define _HELPER_H

class Node1
{
private:
    int data;
    Node1* next;

public:
    Node1(int data);
   /* {
        this->data = data;
        this->next = nullptr;
    }*/
    friend class SignlyLinearLinkedList;
    friend class SinglyCircularLinkedList;
};

class Node2
{
private:
    int data;
    Node2* next;
    Node2* prev;

public:
    Node2(int data);
    /*{
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }*/
    friend class DoublyLinearLinkedList;
    friend class DoublyCircularLinkedList;
};

#endif
