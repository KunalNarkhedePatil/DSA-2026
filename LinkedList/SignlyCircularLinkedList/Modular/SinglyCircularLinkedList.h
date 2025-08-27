#include<iostream>

class Node
{
private:
	int data;
	Node* next;

public:

	Node(int value) :data(value), next(nullptr) {}

	friend class SinglyCircularLinkedList;
};

class SinglyCircularLinkedList
{
private:
	Node* first;
	Node* last;
	int iSize;

public:

SinglyCircularLinkedList();
~SinglyCircularLinkedList();

void insertAtFirst(int data);
void insertAtLast(int data);
void insertAtPos(int data,int pos);

void deleteAtFirst();
void deleteAtLast();
void deleteAtPos(int pos);

void display();

int count();
};