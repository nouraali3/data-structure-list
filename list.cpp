#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "Node.cpp"

class list{
	private:
		Node *head;
	public:
		list(){head=NULL;}
		list(int d){head=new Node(d);}
		void Insert(int data,int n);
		//void Insert(int data,int n,int p);
		int get(int i);//get data at index i
		void Insert(int d);
		void Print();
		bool IsEmpty();
		int Count();
		float AvgSum();
		void Inverse();
		void Delete(int element);
		Node *gethead()
		{
			return head;
		}
friend class polynomial;
};

void list::Insert(int d)
{
	Node * temp= head;
	if(head== NULL) 
		head = new Node(d);
	else
	{ 
		for(; temp->next!= NULL; temp=temp->next);
		temp->next= new Node(d);
	}
}

void list::Insert(int data,int n)
{
	Node* temp1=new Node();
	temp1->data =data;
	temp1->next =NULL;
	if (n==1)
	{
		temp1->next=head;
		head=temp1;
		return;
	}
	else {
		Node* temp2=head;
	    for(int i=0;i<n-2;i++)
	    {
		temp2=temp2->next;
        }
	    temp1->next=temp2->next;
	    temp2->next=temp1;
	    return;
	}
}

//int list::get(int i) //insert at certain index
//{
//	if(head=null)
//	{
//		if (i==0)
//			return head->getdata();
//		Node* temp=head;
//		else
//		{
//		    for(int j=0;j<i-2;j++)
//				temp=temp->next;
//		    return temp->getdata();
//		}
//	}
//}

void list::Print()
{
	Node* temp=head;
	if(temp==NULL)
	cout<<"list is Empty";
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

bool list::IsEmpty()
{
    return head==NULL;
}

int list::Count()
{
	Node *temp=head;
	if (temp==NULL)
	return 0;
	//temp=head;
	int c=1;  // (1)c=0
	while(temp->next!=NULL) // (1) && ==while(temp!=NULL)
	{
		c++;
		temp=temp->next;
	}
	return c;
}

float list::AvgSum(){
	Node *temp=head;
	if (temp==NULL)
	return 0;
	float sum=0;
	while(temp!=NULL)
	{
		sum+=temp->data;
		temp=temp->next;
	}
	return sum/Count();
}


void list::Inverse()
{
	if(head==NULL)
	return;
	else if(head->next==NULL)
	return;
	Node *tmp=head;
	Node *prev=NULL;
	Node *n=tmp->next;
	while (tmp!=NULL)
	{
		tmp->next=prev;
		prev=tmp;
		tmp=n;
		if (n!=NULL)
		n=tmp->next;
	}
	head=prev;
}

void list::Delete (int element)
{
	int i;
	if (head==NULL)
	return;
	Node *temp=head;
	while (temp->next->data != element)
	{
		if(temp==NULL)
		    return;
		temp=temp->next;
	}
	Node *temp2 = temp->next;
	temp->next=temp->next->next;
	free(temp2);  	
}


