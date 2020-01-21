//============================================================================
// Name        : PostFix.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//#include<bits/stdc++.h>
#include<iostream>
#define MAX 256
using namespace std;

class Node
{
	char c;
	Node *next;
public:
	Node();
	Node(char);
	void display();

	friend class Stack;
};
Node::Node()
{
	c='(';
	next=NULL;
	
}
Node::Node(char a)
{
   c=a; next=NULL;  
}

class Stack
{
	Node *start;
	public:
	Stack(){  start=new Node();}
          void push(char);
           void pop();
           void display();
           char peek();
           int isEmpty();
};

void Stack::push(char a)
{
     Node *temp=new Node(a);
     temp->next=start;
     start=temp;
}

void Stack::pop()
{
if(start==NULL)
{cout<<"Stack is Empty"<<endl;
return;}
        Node* temp=start;
	start=start->next;
	delete temp;
}

char Stack::peek()
   {
if(start==NULL)
{cout<<"Stack is Empty!"<<endl; return '#';}
   	return (start->c);
   }

void Stack::display()
{
	Node*t=start;
	while(t!=NULL){
		cout<<t->c<<" "<<endl;
		t=t->next;
	}
}

int Stack::isEmpty()
{
	if(start==NULL)
	{return 1;}
	else
	{return 0;}
}

class String
{
   
   char arr[MAX];
public:
   String()
   {  arr[0]='\0';}
   void read();
   void display();
   void append(char);
   int isp(char);
   int isOperator(char);
   String toPostfix();
   float evaluate();
   int getLength();
};

void String::read()
{
cin>>arr;
}

void String::display(){
	cout<<arr<<endl;
}

int String::getLength()
{
	int i=0;
	for(i=0;arr[i]!='\0';i++);
	return i;
}

void String::append(char a)
{
	int i;
	for(i=0;arr[i]!='\0';i++);
	arr[i]=a;
	arr[i+1]='\0';
}

     int String:: isp(char a)
     {
    	 if(a=='*' || a=='/')
    	 {  return 2;    	 }
    	 else if(a=='+' || a=='-')
    	 {   return 1;  }
    	 else if(a=='(')
    	 {   return -1; }
     }

int String::isOperator(char a)
{
	if( a=='+' || a=='-' || a=='*' || a=='/' )
    { return 1; }
	else {return 0;}
}

String String::toPostfix()
{
	
	Stack s;
	char sym,top;
	String exp;
	int i=0;
	for(i=0;arr[i]!='\0';i++);
	arr[i]=')';
	arr[i+1]='\0';
        arr[i+2]='\0';
    for(;i>=0;i--){arr[i+1]=arr[i];}
        arr[0]='(';
	for(i=0;arr[i]!='\0';i++)
	{
		sym=arr[i];
		if(sym=='('){s.push(sym);}
		else if(sym==')' && !s.isEmpty()){
                    	while(s.peek()!='('){
						exp.append(s.peek());
						s.pop();
						
					}
					s.pop();
				}
				else if(isOperator(sym)){
					top=s.peek(); 
					if(isp(top)<isp(sym))
						s.push(sym);
					
					else{
						while(isp(top)>=isp(sym)){
							exp.append(s.peek());
							s.pop();
							top=s.peek();
							s.push(sym);
						}
						//s.push(sym);
					}
				}
				else if(isalpha(sym)||isdigit(sym)){
					exp.append(sym);
				}
				/*else{cout<<"HH1"<<endl;
					exp.arr[0]='\0';
					break;
				}*/
          }
	
			if(s.isEmpty()){ 
				exp.arr[0]='\0';}
			return exp;
}

class Numbers{
	int top;
	float num[256];
public:
	Numbers(){top=-1;}
	void push(float);
	void pop();
	float peek();
	bool isEmpty();
	bool isFull();
	~Numbers(){
			top=-1;
	}
};
void Numbers::push(float a)
{
      top++;
      if(top<256)
      {
    	  num[top]=a;
      }
      else
      {
      			cout<<"Stack is FULL";
      			top--;
      }
}

void Numbers::pop(){
		if(top==-1){
			cout<<"Stack -> EMPTY!";
			return;
		}
		top--;
}

float Numbers::peek()
   {
	if(top==-1)
				return '#';
	return num[top];
   }

bool Numbers:: isEmpty(){
		return top==-1;
	}


	bool Numbers::isFull(){
		return top==256;
}


float String::evaluate(){
	Stack s;
	char sym;
	float a,b;
	Numbers n;
	for(int i=0;arr[i]!='\0';i++){
		sym=arr[i];
		if(isalpha(sym)){
			cout<<"Enter the Value of "<<sym<<": ";
			cin>>a;
			n.push(a);
		}
		else if(isdigit(sym)){
			a=sym-'0';
			n.push(a);
		}
		else if(isOperator(sym)&&!n.isEmpty()){
			b=n.peek();
			if(n.isEmpty()){
				cout<<"Undefined Expression!";
				cout<<"\nREASON:- Operator(s) MisMatch";
				return 0;
			}
			n.pop();
			a=n.peek();
			if(s.isEmpty()){
				cout<<"Undefined Expression!";
				cout<<"\nREASON:- Operator(s) MisMatch";
				return 0;
			}
			n.pop();
			switch(sym){
				case '+': n.push(a+b);
							break;
				case '-': n.push(a-b);
							break;
				case '*': n.push(a*b);
							break;
				case '/': n.push(a/b);
							break;
			}
		}
		else{
			cout<<"Undefined Expression!";
			cout<<"\nREASON:- Operator(s) MisMatch";
			return 0;
		}
	}
	cout<<arr<<" = ";
	return n.peek();
}


int main()
{
    String in,post;
    Stack o;
    string s;
    cout<<"*******INFIX TO POSTFIX OPERATOR*********"<<endl;

    int f=1;
    	while(f){
    		cout<<endl<<"Enter the expression"<<endl;
    		in.read();
    		post=in.toPostfix();
              cout<<endl;
    		if(post.getLength()){
    			cout<<"Postfix Expression is: ";
    			post.display();
    			cout<<"\n\nAnswer of the above expression : ";
    			cout<<"\n";
    			cout<<post.evaluate();
    		}
    		else
    			cout<<"\nInvalid Infix Expression!";
    		cout<<"\n\n---------------------------------------------------------";
    		cout<<"\nDo You Want to Enter Another Expression(0/1): ";
    		cin>>f;
    }
}

