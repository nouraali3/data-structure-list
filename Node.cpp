#include <stdlib.h>
#include <stdio.h>
#include<iostream>

using namespace std ;
class Node
{
	private:
	int data;
	int power;
	Node* next; 
	
	public:
		Node()
		{
			data=0;
			power=0;
			next=NULL;
		}
		Node(int d)
		{
			data=d;
			power=0;
			next=NULL;
		}
		Node(int d,int p)
		{
			data=d;
			power=p;
			next=NULL;
		}
		int getdata()
		{
			return data;
		}
		int setdata(int d)
		{
			data=d;
		}
		Node* getnext()
		{
			return next;
		}
		int getpower()
		{
			return power;
		}
		
		friend class list;
		friend class polynomial;
};



