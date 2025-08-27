#include "ISinglyLinkedList.h"
#include "SinglyLinkedList.h"

// Factory Method Implementation
ISinglyLinkedList* ISinglyLinkedList::getInstance()
{
    return new SinglyLinkedList();
}
