#include "ISinglyCircularLinkedList.h"
#include "SinglyCircularLinkedList.h"

ISinglyCircularLinkedList* ISinglyCircularLinkedList::getInstance()
{
    return new SinglyCircularLinkedList();
}

void ISinglyCircularLinkedList::relaseInstance(ISinglyCircularLinkedList* instance)
{
    delete instance;
    instance=  NULL;
}
