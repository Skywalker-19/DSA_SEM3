//============================================================================
// Name        : DeQ.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*#include<bits/stdc++.h>
using namespace std;
#define MAX 10
class Deque{
	int arr[MAX];
	int front;
	int rear;
	int size;
public:
	Deque();
	void menu();
	void pushFront(int);
	void pushBack(int);
	void popFront();
	void popBack();
	void display();
	void display0();
	bool isEmpty();
	bool isFull();
	int peekFront();
	int peekBack();
};

Deque::Deque(){
	front=0;
	rear=-1;
	size=0;
	for(int i=0;i<MAX;i++)
		arr[i]=0;
}

bool Deque::isEmpty(){
	if(front==0) {return 1;}
	else {return 0;}
}

bool Deque::isFull(){

	if(front==0 && rear==((front+1)%MAX) )
	    return 1;
	else
		return 0;
}

void Deque::pushFront(int key){
	if(isFull()){
		cout<<"\n Deque Full!";
		return;
	}
	size++;
	arr[front]=key;
	front=(front+1)%MAX;
	cout<<key<<" Added at Front";
}

void Deque::pushBack(int key){
	if(isFull()){
		cout<<"\nError: Deque Full!";
		return;
	}
	size++;
	arr[rear+MAX]=key;
	rear=(rear-1)%MAX;
	cout<<key<<" Added at Rear";
}

void Deque::popFront(){
	if(isEmpty()){
		cout<<"\nError: Deque Empty!";
		return;
	}
	size--;
	cout<<"\nFront Popped!";
	front=(front-1)%MAX;
}

void Deque::popBack(){
	if(isEmpty()){
		cout<<"\nError: Deque Empty!";
		return;
	}
	size--;
	cout<<"\nRear Popped!";
	rear=(rear+1)%MAX;
}

int Deque::peekFront(){
	int index=(front-1)%MAX;
	return(arr[index]);
}

int Deque::peekBack(){
	int index=(rear+1)%MAX+MAX;
	return(arr[index]);
}

void Deque::display(){
	cout<<"\nDeque: ";
	for(int i=front-1;i>rear;i--){
		if(i>=0)
			cout<<arr[i%MAX]<<" ";
		else
			cout<<arr[i%MAX+MAX]<<" ";
	}
	cout<<"\nNo. of Elements in Deque = "<<size;
	return;
}

void Deque::display0(){
	cout<<"\n";
	for(int i=0;i<MAX;i++)
		cout<<arr[i]<<" ";
	cout<<"\nfront = "<<front;
	cout<<"\nrear = "<<rear;
}

void Deque::menu(){
	cout<<"\n-----------------DEQUE OPERATIONS-------------------";
	cout<<"\nPress 1: Push Element at Front";
	cout<<"\nPress 2: Push Element at Back";
	cout<<"\nPress 3: Pop Element at Front";
	cout<<"\nPress 4: Pop Element at Back";
	cout<<"\nPress 5: Display Deque";
	cout<<"\nPress 8: Developer Display;";
	cout<<"\nPress 9: Display Operations";
}
int main(){
	Deque container;
	int choice,key;
	container.menu();
	do{
		cout<<endl<<"*****************************************";
		cout<<endl<<"Enter Choice [Press 0 to exit]: ";
		cin>>choice;
		switch(choice){
			case 1: cout<<"\nEnter Element: ";cin>>key;
					container.pushFront(key);
					break;
			case 2: cout<<"\nEnter Element: ";cin>>key;
					container.pushBack(key);
					break;
			case 3: container.popFront();
					break;
			case 4: container.popBack();
					break;
			case 5: container.display();
					break;
			case 8: container.display0();
					break;
			case 9: container.menu();
					break;
			case 0: cout<<"\nPROGRAM TERMINATED!\n";
					break;
			default: cout<<"\nInvalid Choice Entered!";
		}
	}while(choice);
	return 0;
}*/


// C++ implementation of De-queue using circular
// array
#include<iostream>
using namespace std;

// Maximum size of array or Dequeue
#define MAX 100

// A structure to represent a Deque
class Deque
{
    int  arr[MAX];
    int  front;
    int  rear;
    int  size;
public :
    Deque(int size)
    {
        front = -1;
        rear = 0;
        this->size = size;
    }

    // Operations on Deque:
    void  insertfront(int key);
    void  insertrear(int key);
    void  deletefront();
    void  deleterear();
    bool  isFull();
    bool  isEmpty();
    int  getFront();
    int  getRear();
    void menu();
    void display();
};

// Checks whether Deque is full or not.
bool Deque::isFull()
{
    return ((front == 0 && rear == size-1)||
            front == rear+1);
}

// Checks whether Deque is empty or not.
bool Deque::isEmpty ()
{
    return (front == -1);
}

// Inserts an element at front
void Deque::insertfront(int key)
{
    // check whether Deque if  full or not
    if (isFull())
    {
        cout << "Overflow\n" << endl;
        return;
    }

    // If queue is initially empty
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }

    // front is at first position of queue
    else if (front == 0)
        front = size - 1 ;

    else // decrement front end by '1'
        front = front-1;

    // insert current element into Deque
    arr[front] = key ;
}

// function to inset element at rear end
// of Deque.
void Deque ::insertrear(int key)
{
    if (isFull())
    {
        cout << " Overflow\n " << endl;
        return;
    }

    // If queue is initially empty
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }

    // rear is at last position of queue
    else if (rear == size-1)
        rear = 0;

    // increment rear end by '1'
    else
        rear = rear+1;

    // insert current element into Deque
    arr[rear] = key ;
}

// Deletes element at front end of Deque
void Deque ::deletefront()
{
    // check whether Deque is empty or not
    if (isEmpty())
    {
        cout << "Queue Underflow\n" << endl;
        return ;
    }

    // Deque has only one element
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        // back to initial position
        if (front == size -1)
            front = 0;

        else // increment front by '1' to remove current
            // front value from Deque
            front = front+1;
}

// Delete element at rear end of Deque
void Deque::deleterear()
{
    if (isEmpty())
    {
        cout << " Underflow\n" << endl ;
        return ;
    }

    // Deque has only one element
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
        rear = size-1;
    else
        rear = rear-1;
}

// Returns front element of Deque
int Deque::getFront()
{
    // check whether Deque is empty or not
    if (isEmpty())
    {
        cout << " Underflow\n" << endl;
        return -1 ;
    }
    return arr[front];
}

// function return rear element of Deque
int Deque::getRear()
{
    // check whether Deque is empty or not
    if(isEmpty() || rear < 0)
    {
        cout << " Underflow\n" << endl;
        return -1 ;
    }
    return arr[rear];
}

void Deque::menu(){
	cout<<"\n-----------------DEQUE OPERATIONS-------------------";
	cout<<"\nPress 1: Push Element at Front";
	cout<<"\nPress 2: Push Element at Back";
	cout<<"\nPress 3: Pop Element at Front";
	cout<<"\nPress 4: Pop Element at Back";
	cout<<"\nPress 5: Display Deque";
	cout<<"\nPress 8: Developer Display;";
	cout<<"\nPress 9: Display Operations";
}

void Deque::display(){
	cout<<"\nDeque: ";
	for(int i=front-1;i>rear;i--){
		if(i>=0)
			cout<<arr[i%MAX]<<" ";
		else
			cout<<arr[i%MAX+MAX]<<" ";
	}
	cout<<"\nNo. of Elements in Deque = "<<size;
	return;
}
// Driver program to test above function
int main()
{
    Deque dq(5);
    int choice,key;
    	dq.menu();
    	do{
    		cout<<endl<<"*****************************************";
    		cout<<endl<<"Enter Choice [Press 0 to exit]: ";
    		cin>>choice;
    		switch(choice){
    			case 1: cout<<"\nEnter Element: ";cin>>key;
    					dq.insertfront(key);
    					break;
    			case 2: cout<<"\nEnter Element: ";cin>>key;
    					dq.insertrear(key);
    					break;
    			case 3: dq.deletefront();
    					break;
    			case 4: dq.deleterear();
    					break;
    			case 5: dq.display();
    					break;
    			//case 8: container.display0();
    					//break;
    			case 9: dq.menu();
    					break;
    			case 0: cout<<"\nPROGRAM TERMINATED!\n";
    					break;
    			default: cout<<"\nInvalid Choice Entered!";
    		}
    	}while(choice);
    return 0;
}


