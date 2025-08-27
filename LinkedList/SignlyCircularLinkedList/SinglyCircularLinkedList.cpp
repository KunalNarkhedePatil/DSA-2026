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

	SinglyCircularLinkedList()
	{
		first = NULL;
		last = NULL;
		iSize = 0;
	}

	void insertAtFirst(int data)
	{
		Node* newn = new Node(data);
		if (NULL == first && last == NULL)
		{
			first=newn;
            last=newn;
           
		}
		else
		{
			newn->next=first;
            first=newn;
		}
       last->next=first;
		iSize++;
	}
	void insertAtLast(int data)
	{
		Node* newn = new Node(data);

		if (NULL == first && NULL == last)
		{
			first = newn;
			last = newn;
		}
		else
		{
			last->next = newn;
			last = newn;
		}
        last->next=first;
		iSize++;
	}
	void insertAtPos(int data, int pos)
	{
		if (pos<1 || pos>iSize+1)
		{
			std::cout << "Invalid position" << std::endl;
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
            Node *temp=first;
			for (int i = 1;i < pos - 1;i++)
			{
				temp = temp->next;
			}

			newn->next = temp->next;
			temp->next = newn;
			iSize++;
		}

	}

	void deleteAtFirst()
	{
        if(first==NULL && last==NULL)
        {
            std::cout<<"Linked list is empty"<<std::endl;
            return;
        }
        if(first==last)
        {
            delete first;
            first=NULL;
            last=NULL;
        }
        else
        {
            Node *temp=first;
            first=first->next;
            delete temp;
            temp=NULL;
            last->next=first;
        }

        iSize--;
	}
	void deleteAtLast()
	{
       if(NULL==first && NULL==last)
       {
          std::cout<<"Linked list is empty"<<std::endl;
          return;
       }

       if(first==last)
       {
          delete first;
          first=NULL;
          last=NULL;
       }
       else 
       {
           Node *temp=first;

           while(temp->next!=last)
           {
              temp=temp->next;
           }

           delete temp->next;
           temp->next=first;
           last=temp;
       }
       iSize--;
	}
	void deleteAtPos(int pos)
	{
        if(pos<1 || pos>iSize)
        {
            std::cout<<"Invalid position"<<std::endl;
            return;
        }

        if(pos==1)
        {
            deleteAtFirst();
        }
        else if(pos==iSize)
        {
            deleteAtLast();
        }
        else
        {
            Node *temp=first;

            for(int i=1;i<pos-1;i++)
            {
                temp=temp->next;
            }

            Node* targated=temp->next;
            temp->next=targated->next;
            delete targated;
            targated=NULL;
            iSize--;
        }
	}

	void display()
	{
		if(NULL==first && NULL==last)
        {
            std::cout<<"Linked list is empty"<<std::endl;
            return;
        }

        Node* temp=first;

        do
        {
            std::cout<<temp->data;
            if(temp->next!=last->next)
            {
                std::cout<<"->";
            }
            temp=temp->next;
        }
        while(temp!=last->next);
        std::cout<<std::endl;
        
	}

	int count()
	{
		return iSize;
	}
};
int main()
{

	SinglyCircularLinkedList sobj;

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

	sobj.display();

	std::cout << "Number of nodes are:" << sobj.count() << std::endl;
	return 0;
}