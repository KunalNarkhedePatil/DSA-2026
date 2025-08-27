#include <iostream>
using namespace std;

// typedef Node* PNODE;
class Node
{
    // friend class SinglyLL;
public:
    int data;
    Node *next;

public:
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

class SinglyLL
{
private:
    Node *first;
    int iSize;

public:
    SinglyLL()
    {

        this->first = NULL;
        this->iSize = 0;
    }

    void insertAsSorted(int iVal)
    {

        Node *newn = new Node(iVal);

        if (first == NULL || first->data >= iVal)
        {

            newn->next = first;
            first = newn;
        }
        else
        {

            Node *temp = first;
            while (temp->next != NULL && temp->next->data <= iVal)
            {
                temp = temp->next;
            }

            newn->next = temp->next;
            temp->next = newn;
        }
        iSize++;
    }
    void Display()
    {

        Node *temp = first;

        while (temp != NULL)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    SinglyLL sobj;

    sobj.insertAsSorted(10);
    sobj.insertAsSorted(5);
    sobj.insertAsSorted(15);
    sobj.insertAsSorted(30);
    sobj.insertAsSorted(20);

    sobj.Display();
    return 0;
}