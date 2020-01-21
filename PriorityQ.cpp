//============================================================================
// Name        : PriorityQ.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Node
{
	int n;
	Node *next;
public:
	Node()
    {
		n=0; next=NULL;
    }
	Node(int a)
	{
	   n=a; next=NULL;
	}

	friend class Priority;
};

class Priority{
	Node *start;
public:
	void read();
	void deletef();
    void display();
};

void Priority::read()
{
		int i=0;
		int n;
		Node *t;
		if(start==NULL)
	    	{
			    cout<<"Enter the Task Code "<<endl;
	    		cin>>n;
	    	     start=new Node(n);
	    	     t=start;
	    	}
		else
		{
			cout<<"HI";
	    	     int f=0;
	    	     Node *temp;

	    	          for( ; ;i++)
	    	          {
	    	        	  /*	cout<<"Do you want to add another TASK CODE?(1 for YES/0 for NO)"<<endl;
	    	        	 	    	             cin>>f;
	    	        	 	    	             if(f==1){ goto b; }
	    	        	 	    	             else{ f=0; break;}

	    	              b:*/
	    	        	  f=1;
	    	        	  t=start;
	    	         	 cout<<"Enter the Task Code "<<endl;
	    	      	     cin>>n;
	    	         	Node *present=new Node(n);
	    	             if(present->n > t->n){
	    	         	 present->next=t;
	    	         	 start=present;
	                     }
	    	             else{
	    	            	while(t!=NULL){
	    	            		if(t->n > present->n)
	    	            		{ f=1; }
	    	            		else {f=0; break;}
	    	            		temp=t;
	    	            		t=t->next;
	    	            	}
	    	            	if(f==0)
	    	            	{
	    	            		temp->next=present;
	    	            		present->next=t;
	    	            	}
	    	            	else if(f==1){ temp->next=present;}


	    	            	cout<<"Do you want to add another TASK CODE?(1 for YES/0 for NO)"<<endl;
	    	            	  cin>>f;
	    	            	  if(f==1){ continue; }
	    	            	 else{ f=0; break;}

	    	            }

	    	          }
		}
}

void Priority:: deletef()
{
	Node *t=start;
	start=start->next;
	delete t;
}

void Priority::display()
{
	if(start==NULL)
			{
				cout<<"EMPTY LIST!"<<endl;
			}
		else
		{
		Node *t=start;
		while(t!=NULL)
		{
			cout<<t->n<<"  ";
			t=t->next;
		}
		cout<<endl;
		}
}

int main(){
	Priority ob;
	cout<<"*************Priority Setter Program*************"<<endl;
	int p;
	for( ; ;){
		cout<<"*******MENU*******"<<endl;
		cout<<"1.Insert Element"<<endl;
		cout<<"2.Delete Element"<<endl;
		cout<<"3.Display Priority "<<endl;
		cin>>p;

		switch(p){
		case 1:ob.read();
                cout<<endl;
                cout<<endl; break;
		case 2:ob.deletef(); break;
		case 3:
                 cout<<" Priority of Task Code:- "<<endl;
	             ob.display();
	             break;

		default: cout<<"Enter choice from the MENU!"<<endl;
		}

	cout<<"DO YOU WANT TO PERFORM ANY OTHER OPERATION?(1 for YES/0 for NO)"<<endl;
	cin>>p;
	if(p==1){continue;}
	else{break;}
   }
}
