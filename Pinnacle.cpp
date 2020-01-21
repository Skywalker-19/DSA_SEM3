//============================================================================
// Name        : Pinnacle.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Pinnacle
{
	int prn;
	string name;
	Pinnacle *next;
public:
	Pinnacle();
	Pinnacle(int,string);
	void display();
	friend class Club;
};
class Club
{
	Pinnacle *start;
public:
	Club();
	Club(int n);
	void read(int n);
	void display();
	void insert(int,string);
	void addPresi(int,string);
	void addSec(int,string);
	void addList();
	void delList();
	void delSec();
	void delPresi();
	int total();
	void sortpnr();
	void concat(Club);
	void callrec();
	void revrec(Pinnacle *);

};

Club::Club()
{
	start=NULL;
}
Pinnacle::Pinnacle()
{
	next=NULL; prn=0; name="";
}
Pinnacle::Pinnacle(int p,string st)
{
	prn=p;
	name=st;
	next=NULL;
}
void Pinnacle::display()
{
	cout<<prn<<"  "<<name<<endl;;
}
void Club::read(int p)
{
	int i=0;
	int prn;
	string name;
	Pinnacle *t;
    if(start!=NULL)
    {
    t=start;
     i=1;
    }
    else
    {
    	cout<<"Enter the PRN number of the Student 1"<<endl;
    		cin>>prn;
    		cout<<"Enter the Name of the Student 1"<<endl;
    		cin>>name;
    	     start=new Pinnacle(prn,name);
    	     t=start;
    	     i=2;
    }
    	          for( ;i<=p;i++)
    	          {
    	         	 cout<<"Enter the PRN number of the Student "<<i<<endl;
    	      	     cin>>prn;
    	      	     cout<<"Enter the Name of the Student "<<i<<endl;
    	      	     cin>>name;
    	         	Pinnacle *present=new Pinnacle(prn,name);
    	         	t->next=present;
    	         	t=present;
                   }
 }


void Club::display()
{
	if(start==NULL)
		{
			cout<<"EMPTY LIST!"<<endl;
		}
	else
	{
	Pinnacle *t=start;
	while(t!=NULL)
	{
		t->display();
		t=t->next;
	}
	}
}

void Club::addPresi(int p,string s)
{
	Pinnacle *temp=new Pinnacle(p,s);
	if(start==NULL)
	{start=temp;}
	else
	{
		temp->next=start;
		start=temp;
	}
}

void Club::delPresi()
{
	if(start==NULL)
	{
		cout<<"PRESIDENT NOT FOUND"<<endl;
	}
	else
	{
		start=start->next;
	}
}
void Club::addSec(int p,string s)
{
	Pinnacle *t=start;
	Pinnacle *temp=new Pinnacle(p,s);
	if(start==NULL)
	{cout<<"NO PRESIDENT"<<endl;}
	else
	{
		while(t->next!=NULL)
		{
			t=t->next;
		}
			temp->next=NULL;
		    t->next=temp;

	}
}

void Club::delSec()
{
	Pinnacle *t=start;
	if(start==NULL)
	{
		cout<<"SECRETARY NOT FOUND"<<endl;
	}
	else
	{
	while((t->next)->next!=NULL)
	{
		t=t->next;
	}
	t->next=NULL;
	}
}

int Club::total()
{
	int c=1;
	if(start==NULL)
		{
			cout<<"EMPTY LIST!"<<endl;
		}
	else
	{
	Pinnacle*t=start;
	while(t->next!=NULL)
	{
		t=t->next;
		c++;
	}
	}
	return c;
}

void Club::addList()
{
	int n=0,k=1,prn;
	string name="";
	int f=total();
	for(;;)
	{
		k=1;
	cout<<"Enter the position in which Member has to be added"<<endl;
	cin>>n;
	if(n==1 || n==f)
	{
		cout<<"Can't enter at first position and last position as President are Secretary are entered "<<endl;
		cout<<"Do you want to enter another Position?(1 for yes/0 for no)"<<endl;
		cin>>k;
		if(k==1){continue;}
		else{break;}
	}
	else
	{break; }
	}

	if(k!=0)
	{
		Pinnacle *t=start;
		cout<<"Enter the PRN number of the Student "<<endl;
	    cin>>prn;
	     cout<<"Enter the Name of the Student "<<endl;
 	     cin>>name;
 	     Pinnacle *present=new Pinnacle(prn,name);

		for(int i=1;i<(n-1);i++)
		{
			t=t->next;
		}
		present->next=t->next;
		t->next=present;
	}
}

void Club::delList()
{
	Pinnacle *t=start;
	int prn;
	if(start==NULL)
	{
			cout<<"EMPTY LIST!"<<endl;
    }
	else
	{
	cout<<"Enter the PRN Number of the Student to be deleted from the list"<<endl;
	cin>>prn;
	for(int i=1;(t->next)->prn==prn;i++)
	{
		t=t->next;
	}
	t->next=(t->next)->next;
	}
}

void Club::sortpnr()
{
	Pinnacle *i,*j;
	int tprn;
	string tname;
	if(start==NULL)
	{cout<<"List is empty"<<endl;}
	else
   {
	for(i=start;i->next!=NULL;i=i->next)
	{
		for(j=start;j->next!=NULL;j=j->next)
		{
			if((j->prn) > j->next->prn)
			{
				tprn=j->prn;
				tname=j->name;
			    j->prn=j->next->prn;
			    j->name=j->next->name;
			    j->next->prn=tprn;
			    j->next->name=tname;
			}
		}
	 }
	cout<<"LIST SORTED!"<<endl;
   }
}

void Club::concat(Club ob2)
{
     Pinnacle *t=start;
     while(t->next!=NULL)
     {
    	 t=t->next;
     }
     t->next=ob2.start;
}

void Club::callrec()
{
	if(start==NULL)
	{
		cout<<"EMPTY LIST!"<<endl;
	}
	else
	{
		Pinnacle *t=start;
		revrec(t);
	}
}

void Club::revrec(Pinnacle *t)
{
	if(t==NULL)
	{
		return;
	}
	else
	{
		revrec(t->next);
		cout<<(t->prn)<<" "<<(t->name)<<endl;
	}
}

int main()
{
	int n,p,c,k;string st;

	Club ob,ob2;;

	for(; ;)
		{
		cout<<"............Student Pinnacle.........."<<endl;
		cout<<"Enter 1 to CONSTRUCT A LIST"<<endl;
		cout<<"Enter 2 to ADD PRESIDENT"<<endl;
		cout<<"Enter 3 to ADD SECRETARY"<<endl;
		cout<<"Enter 4 to DISPLAY THE LIST"<<endl;
		cout<<"Enter 5 to ADD A MEMBER"<<endl;
		cout<<"Enter 6 to DELETE A MEMBER"<<endl;
		cout<<"Enter 7 to DELETE PRESIDENT"<<endl;
		cout<<"Enter 8 to DELETE SECRETARY"<<endl;
		cout<<"Enter 9 to FIND TOTAL NUMBER OF MEMBERS"<<endl;
		cout<<"Enter 10 to SORT ACCORING PNR NUMBER"<<endl;
		cout<<"Enter 11 to PRINT REVERSE LIST"<<endl;
		cout<<"Enter 12 to CONCAT TWO LISTS"<<endl;

		cin>>c;
		switch(c)
		{
		case 1: cout<<"Enter number of students"<<endl;
		        cin>>n;
		        ob.read(n);
		        break;

		case 2: cout<<"Enter President Details"<<endl;
		        cout<<"Enter PRN of PRESIDENT"<<endl;
		        cin>>p;
		        cout<<"Enter NAME of PRESIDENT"<<endl;
		        cin>>st;
		        ob.addPresi(p,st);
		        break;

		case 3:
			      cout<<"Enter SECRETARY Details"<<endl;
	    	        cout<<"Enter PRN of SECRETARY"<<endl;
			        cin>>p;
			        cout<<"Enter NAME of SECRETARY"<<endl;
			        cin>>st;
			        ob.addSec(p,st);
			        break;

		case 4:    ob.display();
		           break;

		case 5:   ob.addList();
		          break;

		case 6:   ob.delList();
		           break;

		case 7:   ob.delPresi();
		         break;

		case 8:   ob.delSec();
		          break;

		case 9:   k=ob.total();
		          cout<<k<<endl;
		          break;

		case 10: ob.sortpnr();
		         break;

		case 11: ob.callrec();
		         break;

		case 12:
		         cout<<"Enter 2nd List"<<endl;
		         cout<<"Enter number of students"<<endl;
		         cin>>n;
		         ob2.read(n);
		         ob.concat(ob2);
		         break;

		}


		cout<<"DO YOU WANT TO PERFORM ANY OTHER OPERATION?(ENTER 0 FOR NO/1 FOR YES)"<<endl;
		cin>>c;
		if(c==0){break;}
		}

}
