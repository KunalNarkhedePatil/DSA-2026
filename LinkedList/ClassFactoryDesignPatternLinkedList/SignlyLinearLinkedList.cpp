#include"SignlyLinearLinkedList.h"

SignlyLinearLinkedList::SignlyLinearLinkedList()
{
    this->first = NULL;
    this->iSize = 0;
}

SignlyLinearLinkedList::~SignlyLinearLinkedList()
{
    while (iSize > 0)
    {
        deleteAtFirst();
    }
}


void SignlyLinearLinkedList::insertAtFirst(int data)
{
    Node1* newn = new Node1(data);

    if (NULL == first)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    iSize++;
}
void SignlyLinearLinkedList::insertAtLast(int data)
{
    Node1* newn = new Node1(data);

    if (NULL == first)
    {
        first = newn;
    }
    else
    {
        Node1* temp = first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iSize++;
}

void SignlyLinearLinkedList::insertAtPos(int data, int pos)
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
        Node1* newn = new Node1(data);

        Node1* temp = first;

        for (int i = 1;i < pos - 1;i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;

        temp->next = newn;
        iSize++;
    }
}
void SignlyLinearLinkedList::deleteAtFirst()
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
        Node1* temp = first;

        first = first->next;

        delete temp;
        temp = NULL;
    }

    iSize--;
}

void SignlyLinearLinkedList::deleteAtLast()
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
        Node1* temp = first;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iSize--;
}

void SignlyLinearLinkedList::deleteAtPos(int pos)
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
        Node1* temp = first;

        for (int i = 1;i < pos - 1;i++)
        {
            temp = temp->next;
        }
        Node1* targetNode = temp->next;

        temp->next = targetNode->next;

        delete targetNode;
        targetNode = NULL;
        iSize--;
    }

}

void SignlyLinearLinkedList::display()
{
    Node1* temp = first;

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
int SignlyLinearLinkedList::count()
{
    return iSize;
}
