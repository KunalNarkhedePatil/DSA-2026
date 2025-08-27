#include"ILinkedList.h"
#include "SignlyLinearLinkedList.h"
#include "SinglyCircularLinkedList.h"
#include "DoublyLinearLinkedList.h"
#include "DoublyCircularLinkedList.h"
ILinkedList* ILinkedList::getInstance(int type)
{

	if (type == 1)
	{
		return new SignlyLinearLinkedList();
	}
	else if (type == 2)
	{
		return new SinglyCircularLinkedList();
	}
	else if (type == 3)
	{
		return new DoublyLinearLinkedList();
	}
	 else if(type==4)
	 {
	     return new DoublyCircularLinkedList();
	 }
	else
	{
		return nullptr;
	}
}


