#include "SinglyCircularLinkedList.h"
#include <iostream>
using namespace std;

SinglyCircularLinkedList::SinglyCircularLinkedList()
{
    first = nullptr;
    last = nullptr;
    iSize = 0;
}

SinglyCircularLinkedList::~SinglyCircularLinkedList()
{
    while (first != nullptr)
    {
        deleteAtFirst();
    }
}

void SinglyCircularLinkedList::insertAtFirst(int data)
{
    Node* newn = new Node(data);
    if (first == nullptr)
    {
        first = last = newn;
        last->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;
        last->next = first;
    }
    iSize++;
}

void SinglyCircularLinkedList::insertAtLast(int data)
{
    Node* newn = new Node(data);
    if (first == nullptr)
    {
        first = last = newn;
        last->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;
        last->next = first;
    }
    iSize++;
}

void SinglyCircularLinkedList::insertAtPos(int data, int pos)
{
    if (pos < 1 || pos > iSize + 1)
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (pos == 1)
        insertAtFirst(data);
    else if (pos == iSize + 1)
        insertAtLast(data);
    else
    {
        Node* newn = new Node(data);
        Node* temp = first;
        for (int i = 1; i < pos - 1; i++)
            temp = temp->next;

        newn->next = temp->next;
        temp->next = newn;
        iSize++;
    }
}

void SinglyCircularLinkedList::deleteAtFirst()
{
    if (first == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }

    if (first == last)
    {
        delete first;
        first = last = nullptr;
    }
    else
    {
        Node* temp = first;
        first = first->next;
        delete temp;
        last->next = first;
    }
    iSize--;
}

void SinglyCircularLinkedList::deleteAtLast()
{
    if (first == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }

    if (first == last)
    {
        delete first;
        first = last = nullptr;
    }
    else
    {
        Node* temp = first;
        while (temp->next != last)
            temp = temp->next;

        delete last;
        last = temp;
        last->next = first;
    }
    iSize--;
}

void SinglyCircularLinkedList::deleteAtPos(int pos)
{
    if (pos < 1 || pos > iSize)
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (pos == 1)
        deleteAtFirst();
    else if (pos == iSize)
        deleteAtLast();
    else
    {
        Node* temp = first;
        for (int i = 1; i < pos - 1; i++)
            temp = temp->next;

        Node* target = temp->next;
        temp->next = target->next;
        delete target;
        iSize--;
    }
}

void SinglyCircularLinkedList::display()
{
    if (first == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = first;
    do
    {
        cout << temp->data;
        if (temp->next != first)
            cout << "->";
        temp = temp->next;
    } while (temp != first);
    cout << endl;
}

int SinglyCircularLinkedList::count()
{
    return iSize;
}
