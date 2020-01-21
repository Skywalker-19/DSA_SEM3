//============================================================================
// Name        : StudentTraining.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define MAX 10

class Training{
	int roll;
	int size;
	int arr[MAX];
public:
	Training(){
		roll=0;
		size=0;
		arr[0]=0;
	}
	void read(int p);
	void display();
	void sentinel(int);
	void linear_search(int);
	void binary(int);
	int Fibonnaci(int);
	int min(int,int);
};


void Training::read(int p){
	int i=0;
	size=p;
	for( ;i<p;i++){
		cout<<"Enter the roll Number of Student "<<i+1<<endl;
		cin>>arr[i];
	}
}

void Training::display(){
	for(int i=0;i<size;i++)
	{cout<<arr[i]<<"  ";}
    cout<<endl;
}

void Training::sentinel(int key)
{
	int last=arr[size-1];
	arr[size-1]=key;
	int i=0;
	while(arr[i]!=key)
	{i++;}
	arr[size-1]=last;
	if((i<(size-1)) || (key==arr[size-1]))
	{cout<<"Number found at "<<i+1<<endl;}
	else
		cout<<"Number not found!"<<endl;
}

void Training::linear_search(int key)
{
	int f=0;
	for(int i=0;i<size;i++){
		if(arr[i]==key){
			f=1;
			cout<<"Number found at "<<i+1<<endl;
			break;
		}
	}
	if(f==0)
	{cout<<"Number not found!"<<endl;}
}

void Training::binary(int key)
{
	int mid=0;
	int low=0;
	int high=size-1;
	int f=0;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(arr[mid]==key)
		{
		  f=1;
		  cout<<"Number found at "<<mid+1<<endl;
		  break;
		}
		else if(key<arr[mid])
		{ high=mid-1;}
		else if(key>arr[mid])
		{low=mid+1;}
	}
		if(f==0)
		{
			cout<<"Number not found!"<<endl;
		}
}


int Training::min(int x, int y)
{ return (x<=y)? x : y; }


int Training::Fibonnaci(int key)
{

    int fibMMm2 = 0;   // (m-2)'th Fibonacci No.
    int fibMMm1 = 1;   // (m-1)'th Fibonacci No.
    int fibM = fibMMm2 + fibMMm1;  // m'th Fibonacci

    while (fibM <= size)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM  = fibMMm2 + fibMMm1;
    }


    int offset = 0;
    int i=0;

    while (fibM > 0)
    {
        // Check if fibMm2 is a valid location
         i = min(offset+fibMMm2, size-1);


        if (arr[i] < key)
        {
        	if(fibMMm2==0){return -1;} //Condition for avoiding offset and checking if element is not present
            fibM  = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }


        else if (arr[i] > key)
        {
        	if(fibMMm1==1){return -1;}  //Condition for avoiding offset and checking if element is not present
            fibM  = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }


        else return i;
    }

    /* comparing the last element with x */
   // if(fibMMm1 && arr[offset+1]==key)
    	//return (offset+1);

    /*element not found. return -1 */

}

int main() {
	int ch;
	int n;
	int p;
	Training ob;
	for( ;  ;){
	cout<<"\n-----------------STUDENT TRAINING PROGRAM-------------------";
		cout<<"\nPress 1: Enter Student Data";
		cout<<"\nPress 2: Display Student Data";
		cout<<"\nPress 3: Perform Sentinel Search";
		cout<<"\nPress 4: Perform Linear Search";
		cout<<"\nPress 5: Perform Binary Search";
		cout<<"\nPress 6: Perform Fibonnaci Search";
		cin>>ch;
		cout<<endl;
		switch(ch){
		case 1:  cout<<"Enter the Number of Students"<<endl;
		         cin>>n;
		         ob.read(n);
		         break;
		case 2:  ob.display();
		          break;

		case 3:
			      cout<<"SENTINEL SEARCH :"<<endl;
			      cout<<endl;
			      cout<<"Enter the number to be Searched"<<endl;
		          cin>>p;
		          ob.sentinel(p);
		          break;

		case 4:
			     cout<<"LINEAR SEARCH :"<<endl;
	             cout<<endl;
	             cout<<"Enter the number to be Searched"<<endl;
                  cin>>p;
                 ob.linear_search(p);
                 break;

		case 5:
			            cout<<"BINARY SEARCH :"<<endl;
			             cout<<endl;
			             cout<<"Enter the number to be Searched"<<endl;
		                  cin>>p;
		                 ob.binary(p);
		                 break;

		case 6:
			                 cout<<"FIBONNACI SEARCH :"<<endl;
				             cout<<endl;
				             cout<<"Enter the number to be Searched"<<endl;
			                  cin>>p;
			                 p=ob.Fibonnaci(p);
			                 if(p==-1)
			                 { cout<<"Number not found!"<<endl;}
			                 else
			                 {
			                      cout<<"Number found at "<<p+1<<endl;
			                 }
			                 break;
		}
		cout<<"DO YOU WANT TO PERFORM ANY OTHER OPERATION?(1 for YES/0 for NO)"<<endl;
			cin>>p;
			if(p==1){continue;}
			else{break;}
		}
}
