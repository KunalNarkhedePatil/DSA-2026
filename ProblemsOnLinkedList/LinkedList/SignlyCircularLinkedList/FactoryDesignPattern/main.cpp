#include <iostream>
#include "ISinglyCircularLinkedList.h"
using namespace std;

int main()
{
    ISinglyCircularLinkedList* list = ISinglyCircularLinkedList::getInstance();

    list->insertAtFirst(50);
    list->insertAtFirst(40);
    list->insertAtFirst(30);
    list->insertAtFirst(20);
    list->insertAtFirst(10);

    list->insertAtLast(60);
    list->insertAtPos(25, 3);

    list->deleteAtFirst();
    list->deleteAtLast();
    list->deleteAtPos(2);

    cout << "Number of elements: " << list->count() << endl;
    list->display();

   ISinglyCircularLinkedList::relaseInstance(list);
    return 0;
}
