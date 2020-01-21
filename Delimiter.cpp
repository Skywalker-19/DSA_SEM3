//============================================================================
// Name        : Delimiter.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Node
{
	char c;
	Node *next;
public:
	Node()
    {
		c='\0'; next=NULL;
    }
	Node(char a)
	{
	   c=a; next=NULL;
	}

	friend class Expr;
};

class Expr
{
	Node *start;
public:
	Expr(){start=NULL;}
	void push(char ch);
	void pop();
	char peak();
	void display();
	bool valid_parenthesis();
	int isEmpty();
};

void Expr:: push(char ch)
{
	Node *temp=new Node(ch);
		temp->next=start;
		start=temp;
}
void Expr:: pop()
{
		start=start->next;
}

void Expr::display()
{
	Node *t=start;
	while(t!=NULL)
	{
		cout<<t->c<<endl;
		t=t->next;
	}
}
char Expr::peak()
{
	return (start->c);
}

int Expr::isEmpty()
{
	if(start==NULL){return 1;}
	else{return 0;}
}
bool Expr::valid_parenthesis()
{
	if(start==NULL)
	{return true;}
	else
	{return false;}
}
int main()
{
	Expr ob;
	string ex;
	int f=1;
	for( ; ;)
	{
		f=1;
	cout<<"*********Delimiter Balancing Checker*******"<<endl;
	cout<<"Enter an Expression"<<endl;
	cin>>ex;
	int l=ex.length();
	char c;
	int i=0;
	for( ;i<l;i++)
	{

		if(ex[i]=='[' || ex[i]=='{' || ex[i]=='(')
		{
			ob.push(ex[i]);
		}
		else if(ex[i]==']' && !ob.isEmpty())
		{
			c=ob.peak();
			if(c=='[' )
			{ob.pop();}
		}
		else if(ex[i]=='}' && !ob.isEmpty())
				{
			c=ob.peak();
					if(c=='{')
					{ob.pop();}
				}
		else if(ex[i]==')' && !ob.isEmpty())
				{
			c=ob.peak();
					if(c=='(')
					{ob.pop();}
				}
		else
		{
			f=0;
		}
	}
	if(ob.valid_parenthesis()==true && f==1)
	{
		cout<<"VALID EXPRESSION"<<endl;
	}
	else if(f==0)
	{
		cout<<"INVALID EXPRESSION"<<endl;
	}

	cout<<"Do you want to check another expression?(1 for Yes/0 for No)"<<endl;
	cin>>i;
	if(i==1)
	{continue;}
	else
	{break;}
	}

}

