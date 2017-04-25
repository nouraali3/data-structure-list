#include <stdlib.h>
#include<cmath>
#include <stdio.h>
#include <iostream>
#include "list.cpp"

using namespace std;

class polynomial
{
	private:
		list l;
	public:
		list coef(int arr[],int o)
		{
			for(int i=0;i<o;i++)
				l.Insert(arr[i]);
			return l;
		}
		void polynomialPrint(list l1)
		{
			int power = l1.Count()-1;//to get size of the list which is equal to the power+1 of the largest x
			Node *tmp=l1.gethead();
			
			if(tmp->getdata()>=0 )	
					{
						cout<<"P(X) = "<< tmp->getdata()<<"X^"<<power;
						tmp=tmp->getnext();
					}
			else if(tmp->getdata()<0 )
			{
				cout<<"P(X) = "<<tmp->getdata()<<"X^"<<power;
				tmp=tmp->getnext();
			}
			for(int i=1;i<l1.Count();i++)//iterates through all the linked list elements
			{
					if(i!=power && tmp->getdata()>=0 )	
					{
						cout<<"+"<< tmp->getdata()<<"X^"<<power-i;
						tmp=tmp->getnext();
					}
					else if(i!=power && tmp->getdata()<0 )
					{
						cout<<tmp->getdata()<<"X^"<<power-i;
						tmp=tmp->getnext();
					}
					if(i==l1.Count()-1 && tmp->getdata()>=0 )	
					{
						cout<<"+"<< tmp->getdata();
					}
					else if(i==l1.Count()-1 && tmp->getdata()<0 )
					{
						cout<<tmp->getdata();
				    }		
			}
			cout<<endl;
		}			

		double evaluatePolynomial(list l1,int num)
		{
			double n=num;
			int power = l1.Count()-1;	
			Node *tmp=l1.gethead();
			double result =0;
			for(int i=0;i<l1.Count();i++)//iterates through all the linked list elements
			{
				result+=(tmp->getdata())*pow(n,power-i);
				tmp=tmp->getnext();
			}
			return result;
		}
		
		list differentiate(list l1)
		{
			list l2;
			Node *tmp=l1.gethead();
			int power = l1.Count()-1;
			for(int i=0;i<l1.Count()-1;i++)
			{
				l2.Insert(tmp->getdata()*(power-i));
				tmp=tmp->getnext();
			}
			return l2;
		}
		
//		list multiplyPolynomial(list l1,list l2)
//		{
//			list l3; //it is where we will store the resulted polynomial
//			Node *tmp1=l1.gethead();
//			Node *tmp2=l2.gethead();
//			int size1=l1.Count()-1;
//			int size2=l2.Count()-1;
//		   // Multiply two polynomials term by term
//		   // Take ever term of first polynomial
//		   for (int i=0; i<l1.Count(); i++)
//		   {
//		     // Multiply the current term of first polynomial with every term of second polynomial.
//		     for (int j=0; j<l2.Count(); j++)
//		     {
//		     	//prod[i+j] += A[i]*B[j];
//		        l3.Insert(tmp1->getdata()*tmp2->getdata(),(size1-i)+(size2-j),i+j);   //in list l3 setting data,power,at index i+j
//		        tmp2=tmp2->getnext();
//			 }
//		      tmp1=tmp1->getnext();   
//		   }
//		   return l3;
//		}
};

int main()
{
	polynomial p;
	int order; int d,n; 
	cout<<"please enter order of the polynomial: "<<endl;
	cin>>order; 
	int a[order];
	for(int i=0;i<order;i++)
	{
		cout<<"coefficient of x^"<<order-1-i<< " = ";
		cin>>a[i];
	}
	cout<<endl;
	list coefficients=p.coef(a,order);   //creating list of coefficients
	p.polynomialPrint(coefficients); //printing polynomial
	cout<<"Solve for X = ";
	cin>>n;
	double r=p.evaluatePolynomial(coefficients,n);//evaluating polynomial
	cout<<"P("<< n<<")="<<r<<endl;
	list derivativeList=p.differentiate(coefficients);//creating derivative list
	cout << "polynomial derivative ";
	p.polynomialPrint(derivativeList);//printing differentiated polynomial
//	list coefficients1;
//	coefficients1.Insert(1);
//	coefficients1.Insert(2);
//	coefficients1.Insert(3);
//	coefficients1.Print();
//	list product=p.multiplyPolynomial(coefficients,coefficients1);
//	p.polynomialPrint(product);
	system("pause");

	
}
