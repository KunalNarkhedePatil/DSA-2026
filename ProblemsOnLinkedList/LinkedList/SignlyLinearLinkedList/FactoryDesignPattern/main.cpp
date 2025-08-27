#include "ISinglyLinkedList.h"

int main()
{
    // Use Factory Method
    ISinglyLinkedList* list = ISinglyLinkedList::getInstance();

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

    std::cout << "Number of elements: " << list->count() << std::endl;

    list->display();

    delete list; // cleanup

    return 0;
}
