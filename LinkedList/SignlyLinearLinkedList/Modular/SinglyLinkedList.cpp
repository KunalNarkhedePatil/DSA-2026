#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList()
{
    first=NULL;
    iSize=0;
}

SinglyLinkedList::~SinglyLinkedList()
{
    while(first)
    {
        deleteAtFirst();
    }

}
void SinglyLinkedList::insertAtFirst(int data)
{
    Node* newn=new Node(data);

    if(NULL==first)
    {
        first=newn;
    }
    else
    {
        newn->next=first;
        first=newn;
    }
    iSize++;
}
void SinglyLinkedList::insertAtLast(int data)
{
    Node* newn = new Node(data);

    if (NULL == first)
    {
        first = newn;
    }
    else
    {
        Node* temp = first;

        while (temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iSize++;
}

void SinglyLinkedList::insertAtPos(int data, int pos)
{
    if (pos<1 || pos>iSize + 1)
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

        for (int i = 1;i < pos - 1;i++)
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
    if (NULL == first)
    {
        std::cout << "Linked list is emmpty" << std::endl;
        return;
    }

    if (NULL == first->next)
    {
        delete first;
        first = NULL;
    }
    else
    {
        Node* temp = first;

        first = first->next;

        delete temp;
        temp = NULL;
    }

    iSize--;
}

void SinglyLinkedList::deleteAtLast()
{
    if (NULL == first)
    {
        std::cout << "invalid position" << std::endl;
        return;
    }

    if (NULL == first->next)
    {
        delete first;
        first = NULL;
    }
    else
    {
        Node* temp = first;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iSize--;
}

void SinglyLinkedList::deleteAtPos(int pos)
{
    if (pos<1 || pos>iSize)
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

        for (int i = 1;i < pos - 1;i++)
        {
            temp = temp->next;
        }
        Node* targetNode = temp->next;

        temp->next = targetNode->next;

        delete targetNode;
        targetNode = NULL;
        iSize--;
    }

}

void SinglyLinkedList::display()
{
    Node* temp = first;

    while (temp != NULL)
    {
        std::cout << temp->data;
        if (temp->next != NULL)
        {
            std::cout << "->";
        }
        temp = temp->next;
    }
    std::cout << std::endl;
}
int SinglyLinkedList::count()
{
    return iSize;
}

int main()
{
    SinglyLinkedList sobj;

    sobj.insertAtFirst(50);
    sobj.insertAtFirst(40);
    sobj.insertAtFirst(30);
    sobj.insertAtFirst(20);
    sobj.insertAtFirst(10);

    sobj.insertAtLast(60);

    sobj.insertAtPos(25,3);

    sobj.deleteAtFirst();
    sobj.deleteAtLast();
    sobj.deleteAtPos(2);

    std::cout<<"Number of elements are:"<<sobj.count()<<std::endl;

    sobj.display();
}
