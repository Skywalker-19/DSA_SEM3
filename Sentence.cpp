//============================================================================
// Name        : Sentence.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Sentence
{
	char st[200];
    public:
	void read();
	void display();
	void copy(Sentence);
	int length();
	Sentence concat(Sentence);
	int substr();
	void reverse();
	int compare();
	int palin();
	Sentence del();
};

void Sentence::read()
{
	cin>>st;
}

void Sentence::display()
{
	int i=0;

	cout<<"The sentence is - "<<endl;
	for(i=0;i<length();i++)
	{

		cout<<st[i];

	}
	cout<<" "<<endl;
}

int Sentence::length()
{
	int i;
	for(i=0;st[i]!='\0';i++);
	return i;

}

void Sentence::copy(Sentence s1)
{
	int i=0;
	for(i=0;i<length();i++)
	{
		s1.st[i]=st[i];
	}
	cout<<"Sentence copied!"<<endl;
}

Sentence Sentence::concat(Sentence s1)
{
	Sentence s3;
	int i,j;
	for(i=0,j=0;i<length();i++,j++)
	{
	s3.st[i]=st[i];
	}
	for(i=0;i<s1.length();i++,j++)
	{
		s3.st[j]=s1.st[i];
	}
	s3.st[j]='\0';
	return s3;
}

int Sentence::substr()
{
	char arr[200];
	cout<<"Enter substring"<<endl;
	cin>>arr;
	int i,j,k,n,g;
	for(n=1;arr[n]!='\0';n++);

	for(i=0;i<length()-n;i++)
	{
		g=-1;
		if(st[i]==arr[0])
		{
			for(j=i,k=0;k<n;j++,k++)
			{
				if(st[j]!=arr[k])
				{g=-1; break;}
				g=1;
			}
			if(g==1)
			{
				return (j-n);
				break;
			}
		}
		int h=length();
		if(g==-1 && i==(h-n-1))
		{
			return g;
			break;
		}

		else{continue;}
	}
}

void Sentence::reverse()
{
	int h=length();
	char a[h];
	int i=0;
	for(i=0;i<h;i++)
	{
		a[i]=st[h-1-i];
	}
	cout<<"The reversed string is - "<<endl;
	for(i=0;i<h;i++)
	{
		cout<<a[i];
	}
	cout<<""<<endl;
}

int Sentence::palin()
{
	int k=0;
	int h=length();
	for(int i=0;i<(h/2);i++)
	{
		if(st[i]==st[h-1-i])
		{k=1;}
		else
		{k=0;}
	}
	return k;
}

Sentence Sentence::del()
{
    Sentence o2;
    int i=0;
    char ch;

    cout<<"Enter the character to be deleted"<<endl;
    cin>>ch;
    int j=0;
    for(i=0;i<length();i++)
    {
    	if(st[i]==ch)
    	{
    		j=1;
    	}
    }
    if(j==0)
    {
    	cout<<"Character not present in the String"<<endl;
    	return o2;
    }
    else
    {
    	j=0;
    for(i=0;i<length();i++)
    {
    	if(st[i]==ch)
    	{continue;}
    	else
    	{
    		o2.st[j]=st[i];
    		++j;
    	}
    }
    o2.st[j]='\0';
    return o2;
    }
}

int Sentence::compare()
{
	char s[200];
	int k=0;
	cout<<"Enter the second String"<<endl;
	cin>>s;
	for(int i=0;i<length();i++)
	{
		if(s[i]==st[i])
		{
			k=1;
		}
		else
		{
			k=0;
			break;
		}
	}
	return k;
}

int main()
{
	Sentence o1,o2,o3;
	int c,k;

	for(; ;)
    {
		cout<<"............STRING OPERATIONS.........."<<endl;
		cout<<"Enter 1 to read STRING from user"<<endl;
		cout<<"Enter 2 to display STRING to the user"<<endl;
		cout<<"Enter 3 to display LENGTH OF STRING to the user"<<endl;
		cout<<"Enter 4 to COPY STRING"<<endl;
		cout<<"Enter 5 to CONCAT TWO STRINGS"<<endl;
		cout<<"Enter 6 to FIND SUBSTRING"<<endl;
		cout<<"Enter 7 to REVERSE THE STRING"<<endl;
		cout<<"Enter 8 to check whether STRING IS PALINDROME"<<endl;
		cout<<"Enter 9 to DELETE A CHARACTER OF STRING"<<endl;
		cout<<"Enter 10 to FIND FREQUENCY OF A CHARACTER IN STRING"<<endl;
		cout<<"Enter 11 to COMPARE TWO STRINGS"<<endl;

		cin>>c;
		switch(c)
		{
			case 1:
				    cout<<"Enter the sentence"<<endl;
				    o1.read();break;

			case 2: o1.display();break;

			case 3: k=o1.length();
			        cout<<k<<endl;;
			        break;

			case 4:
				    o1.copy(o2);
				    o1.display();
				    break;

			case 5:
				    cout<<"Enter the 1st sentence"<<endl;
			        o1.read();
			        cout<<"Enter the 2nd sentence"<<endl;
			        o2.read();
			        o3=o1.concat(o2);
			        o3.display();
			        break;

			case 6:
				    k=o1.substr();
				    if(k>=0)
				    {
				    	cout<<"Substring found at "<<k<<endl;
				    }
				    else
				    {  cout<<"Substring not found"<<endl;
				    break;
				    }

		    case 7:
		    	   o1.reverse();
		    	   break;


		    case 8:
		    	   k=o1.palin();
		    	   if(k==1)
		    	  	 {
		    	  	   cout<<"Palindrome String!"<<endl;
		    	  	 }
		    	  	else
		    	  	{
		    	  	 cout<<"Not a Palindrome String!"<<endl;
		    	  	}
		    	   break;

		    case 9: o3=o1.del();
		             o3.display();
		             break;


		    case 10:
		    case 11:
		    	   k=o1.compare();
		    	   if(k==1)
		    	   {
		    		   cout<<"The two strings are equal!"<<endl;
		    	   }
		    	   else
		    	   {
		    		   cout<<"The two strings are not equal!"<<endl;
		    	   }
		    	   break;

		}
		cout<<"DO YOU WANT TO PERFORM ANY OTHER OPERATION?(ENTER 0 FOR NO/1 FOR YES)"<<endl;
		cin>>c;
		if(c==0){break;}
     }
}

