//============================================================================
// Name        : Binary.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

class Node
{
	int n;
	Node *next;
	Node *prev;
public:
	Node();
	Node(int);
	void display();

	friend class Binary;
};
Node::Node()
{
	n=0;
	next=NULL;
	prev=NULL;
}
Node::Node(int a)
{
   n=a; next=NULL;  prev=NULL;
}

class Binary
{
	Node *start;
public:
	Binary(){start=NULL;};
	void display();
	void compliment();
	int convert(int n);
	Binary add(Binary);

};

int Binary::convert(int p)
{

	int k=p;

	int i=0;
	/*for( ;n!=0;)
	{
		i=n%2;
		s1+=pow(i,c);
		c++;
		n=n/2;
	}
	cout<<s1;
	int s2=s1;
	*/

	start=new Node(k%2);
	k=k/2;
	Node *t=start;

	for( ;k!=1 ;++i)
	{
		Node *temp=new Node(k%2);
		k=k/2;
		t->next=temp;
		temp->prev=t;
		t=t->next;
	}

	if(k==1)
	{
		Node *te=new Node(1);
		t->next=te;
		te->prev=t;
		t=t->next;
	}
	//cout<<k<<endl;
	return 0;
}

void Binary::display()
{
	Node *t=start;
	while(t->next!=NULL)
	{ t=t->next;}
	while(t!=NULL){
		cout<<t->n;
		t=t->prev;
	}


	cout<<endl;
}

void Binary::compliment()
{
	Node *t=start;
	cout<<"1's Compliment is:-"<<endl;
	while(t->next!=NULL)
	{ t=t->next;}
	for(;t!=NULL;)
	{

		if(t->n==0)
		{cout<<"1";}
		else
		{cout<<"0";}
		if(t->prev==NULL)
		{
			break;
		}
		t=t->prev;
	}
	cout<<""<<endl;

	cout<<"2's Compliment is:-"<<endl;
	int c=0;

	string s="";
	for(;t!=NULL;)
	{
		if(t->n==1 && c==0)
		{s+="1"; c=1;}
		else if(t->n==0 && c==0)
		{
			s+="0";
		}
		else if(t->n==1 && c==1)
		{
			s+="0";
		}
		else if(t->n==0 && c==1)
		{
			s+="1";
	    }
		t=t->next;

	}
	cout<<s;
	cout<<endl;
}

Binary Binary::add(Binary o2)
{
	Binary o3;
	int c=0;int s=0;
	Node *t=new Node();
	Node *t1=start;
	Node *t2=o2.start;
	Node *temp;
	for(int i=0;t1!=NULL;i++)
		{
		   if(c==1)
		   {
			   s=c+(t1->n)+(t2->n);
			   if(s==1)
			   {
				   temp=new Node(1);
				   c=0;
			   }
			   else if(s==2)
			   {
				  temp=new Node(0); c=1;
			   }
			   else if(s==3)
			   {
				  temp=new Node(1); c=1;
			   }
		   }
		   else if(t1->n==0 && t2->n==0)
             {
			   temp=new Node(0);
            	c=0;
             }
             else if(t1->n==0 && t2->n==1)
             {
            	temp=new Node(1);
            	 c=0;
             }
             else if(t1->n==1 && t2->n==0)
             {
            	 temp=new Node(1);
            	 c=0;
             }
             else if(t1->n==1 && t2->n==1)
             {
            	 temp=new Node(0);
            	 c=1;
             }
             else if(t1->next==NULL && c==1)
             {
            	 temp=new Node(1);c=1;
             }
		   if(i==0){t=temp;}
		   else
		   {
		   t->next=temp;
		   temp->prev=t;
		   t=t->next;
		   }
		   t1=t1->next;
		   t2=t2->next;
		}
	                  if(c==1)
					     {
						   temp=new Node(1);c=0;
						   t->next=temp;
						  		   temp->prev=t;
						  		   t=t->next;
					     }
	o3.start=t;
	return o3;
}
int main()
{
	int n=0;
	int c;
	Binary o1,ob2,o3;

	for(;;)
	{
	cout<<"............Binary Operations.........."<<endl;
	cout<<"Enter 1 to READ NUMBER from user"<<endl;
	cout<<"Enter 2 to CONVERT TO BINARY NUMBER"<<endl;
	cout<<"Enter 3 to FIND 1's AND 2's COMPLIMENT OF BINARY NUMBER"<<endl;
	cout<<"Enter 4 to ADD TWO BINARY NUMBERS"<<endl;
	cin>>c;
	switch(c)
	{
	case 1:
		    cout<<"Enter Number"<<endl;
			cin>>n;

	        break;
	case 2:
		    o1.convert(n);
		    o1.display();
		    break;
	case 3:
	           o1.compliment();
	           break;

	case 4:
		       cout<<"Enter 1st Decimal Number"<<endl;
					cin>>n;
			        o1.convert(n);
			        o1.display();

			    cout<<"Enter 2nd Decimal Number"<<endl;
			        cin>>n;
			        ob2.convert(n);
			        ob2.display();
			      o3=o1.add(ob2);
			      cout<<"THE SUM IS........"<<endl;
			      o3.display();
			        break;
	}
	    cout<<"DO YOU WANT TO PERFORM ANY OTHER OPERATION?(ENTER 0 FOR NO/1 FOR YES)"<<endl;
		cin>>c;
		if(c==0){break;}
	}
	return 0;
}
