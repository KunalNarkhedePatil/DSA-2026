#include "ILinkedList.h"

int main()
{
    ILinkedList* list = ILinkedList::getInstance(4);

    list->insertAtFirst(50);
    list->insertAtFirst(40);
    list->insertAtFirst(30);
    list->insertAtFirst(20);
    list->insertAtFirst(10);
    list->display();

    list->insertAtLast(60);
    list->display();
    list->insertAtPos(25, 3);
    list->display();
    list->deleteAtFirst();
    list->display();
    list->deleteAtLast();
    list->display();
    list->deleteAtPos(2);
    list->display();

    std::cout << "Number of nodes in the linked list :" << list->count() << std::endl;

    delete list;
    list = nullptr;

    return 0;


}

//g++ main.cpp ILinkedList.cpp SignlyLinearLinkedList.cpp SinglyCircularLinkedList.cpp DoublyLinearLinkedList.cpp DoublyCircularLinkedList.cpp Helper.cpp -o myexe