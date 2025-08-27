#include "SinglyLinkedList.h"

// Constructor
SinglyLinkedList::SinglyLinkedList() : first(nullptr), iSize(0) {}

// Destructor
SinglyLinkedList::~SinglyLinkedList()
{
    clear();
}

// Clear all nodes
void SinglyLinkedList::clear()
{
    while (first)
    {
        deleteAtFirst();
    }
}

void SinglyLinkedList::insertAtFirst(int data)
{
    Node* newn = new Node(data);
    newn->next = first;
    first = newn;
    iSize++;
}

void SinglyLinkedList::insertAtLast(int data)
{
    Node* newn = new Node(data);

    if (!first)
    {
        first = newn;
    }
    else
    {
        Node* temp = first;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iSize++;
}

void SinglyLinkedList::insertAtPos(int data, int pos)
{
    if (pos < 1 || pos > iSize + 1)
    {
        std::cout << "Invalid Position" << std::endl;
        return;
    }

    if (pos == 1)
    {
        insertAtFirst(data);
    }
    else if (pos == iSize + 1)
    {
        insertAtLast(data);
    }
    else
    {
        Node* newn = new Node(data);
        Node* temp = first;

        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
        iSize++;
    }
}

void SinglyLinkedList::deleteAtFirst()
{
    if (!first)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }

    Node* temp = first;
    first = first->next;
    delete temp;
    iSize--;
}

void SinglyLinkedList::deleteAtLast()
{
    if (!first)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }

    if (!first->next)
    {
        delete first;
        first = nullptr;
    }
    else
    {
        Node* temp = first;
        while (temp->next->next)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    iSize--;
}

void SinglyLinkedList::deleteAtPos(int pos)
{
    if (pos < 1 || pos > iSize)
    {
        std::cout << "Invalid Position" << std::endl;
        return;
    }

    if (pos == 1)
    {
        deleteAtFirst();
    }
    else if (pos == iSize)
    {
        deleteAtLast();
    }
    else
    {
        Node* temp = first;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        Node* target = temp->next;
        temp->next = target->next;
        delete target;
        iSize--;
    }
}

void SinglyLinkedList::display()
{
    Node* temp = first;
    while (temp)
    {
        std::cout << temp->data;
        if (temp->next)
            std::cout << " -> ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int SinglyLinkedList::count()
{
    return iSize;
}
