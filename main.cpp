#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "list.cpp"

//using namepace std;

int main(void){
	
	list l;
	//Insert(value,position)
    l.Insert(3,1); // inserting at 1st node list : 3
	l.Insert(4,2); // inserting at 2nd node list : 3 4
	l.Insert(5,1); // inserting at 1st node again list : 5 3 4
	l.Insert(6,2); // inserting at 2nd node again list : 5 6 3 4
	l.Insert(2,5); // list : 5 6 3 4 2
	l.Insert (7); 
	cout <<"list is: ";
	l.Print();
	//Count()
	cout<< "size= "<<l.Count()<<endl;
	//AvgSum
	cout<<"average sum= "<<l.AvgSum()<<endl;
	//IsEmpty()
	cout<<"Empty= "<<l.IsEmpty()<<endl;
	//Inverse list
	l.Inverse(); 
	cout<<"list is: "; //4 3 6 5
	//print inversed list 
	l.Print();
	l.Delete(5);
	l.Print();
	delete(&l);
}
