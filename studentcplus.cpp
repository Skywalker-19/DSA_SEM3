//============================================================================
// Name        : Assignment1.cpp
// Roll No.    : 21165
// Student Name: Swatej Sonawane
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct Student
{
	int roll;
	char name[100];
	float marks;
};
struct Student s[10];
int n;
void read()
{
	int i=0;
	for(i=0;i<n;i++)
		{
		    cout<<"\nEnter Student name"<<endl;
			cin>>s[i].name;
			cout<<"Enter Roll No.";
			cin>>s[i].roll;
			cout<<"Enter marks of the student (-1 for absent student)";
			cin>>s[i].marks;
		}

}
void display()
{
	int i=0;
	for(i=0;i<n;i++)
	{
		cout<<"\nName of the Student: "<<s[i].name;
	    cout<<"\nRoll No.: "<<s[i].roll;
	if(s[i].marks==-1)
	{
		cout<<"\nMarks: Absent"<<endl;
		continue;
	}
	cout<<"\nMarks: "<<s[i].marks<<endl;
	}
}
void avg()
{
	//Average score
	int i=0;
	float sum=0;
	int c=0;
		float avg=0;
		for(i=0;i<n;i++)
		{
			if(s[i].marks==-1)
			{c++; continue;}
			sum=sum+s[i].marks;
		}
		avg=sum/(n-c);
		cout<<"\nAverage of the class is "<<avg<<endl;
}
void highest()
{
	float t=s[0].marks;
    int i=0;
	for(i=0;i<n;i++)
	{
		if(s[i].marks==-1)
					{continue;}
			if(s[i].marks>t)
			{
				t=s[i].marks;
			}
	}
	cout<<"\nHighest marks: "<<t<<endl;
}

	void lowest()
	{

		float t=s[0].marks;
	    int i=0;
		for(i=0;i<n;i++)
		{
			if(s[i].marks==-1)
			{continue;}
				if(s[i].marks<t)
				{
					t=s[i].marks;

		        }
		}
		cout<<"\nLowest marks: "<<t<<endl;
}

	void absent()
	{
		int c=0;
		int i=0;
		for(i=0;i<n;i++)
		{
			if(s[i].marks== -1)
			{
				++c;
			}
		}
		cout<<"\nNo. of absent students : "<< c<<endl;

     }

	void frequency()
	{
		int i,j=0;
		int arr[n];

		for(i=0;i<n;i++)
		{arr[i]=0;}
		for(i=0;i<n;i++)
		{
			if(s[i].marks>=0)
			{
			for(j=0;j<n;j++)
			{
				if(s[i].marks==s[j].marks)
				{
					++arr[i];

				}
			}
			}
		}
		float t=arr[0];
		cout<<"\nFrequency of marks obtained by maximum students:-";
		int g=0;
		for(i=0;i<n;i++)
			{
					if(arr[i]>t)
					{
						t=arr[i];
						g=i;
					}
			}
		cout<<s[g].marks <<" - "<<arr[g];
	}




int main()
{
    int ch=0;
    int f=0;
    cout<<"Enter number of student"<<endl;
	cin>>n;
	cout<<"Enter the details of the student:-"<<endl;
	read();

	for(; ;)
	{
		f=0;
		ch=0;
	cout<<"\nMENU:-";
	cout<<"\nEnter 1 for displaying the result";
	cout<<"\nEnter 2 for Average of the class";
	cout<<"\nEnter 3 for Highest marks of the class";
	cout<<"\nEnter 4 for Lowest marks of the class";
	cout<<"\nEnter 5 for Absent students of the class";
	cout<<"\nEnter 6 for Frequency of the marks";
	cin>>ch;

	switch(ch)
	{
	case 1:display();break;
	case 2:avg();break;
	case 3:highest();break;
	case 4:lowest();break;
	case 5:absent();break;
	case 6:frequency();break;
	default: cout<<"Enter an number from the above"<<endl; f=1;
	}

	if(f==1)
	{
		continue;
	}
	int g=0;
	cout<<"\nDo you want other information? (0 for no/1 for yes)"<<endl;
	cin>>g;
	if(g==1)
	{
	continue;
	}
	else{break;}
}
	return 0;
}

//OUTPUT FOR TEST CASE 1
/*
 Enter number of student
7
Enter the details of the student:-

Enter Student name
A
Enter Roll No.1
Enter marks of the student (-1 for absent student)10

Enter Student name
B
Enter Roll No.2
Enter marks of the student (-1 for absent student)20

Enter Student name
C
Enter Roll No.3
Enter marks of the student (-1 for absent student)30

Enter Student name
D
Enter Roll No.4
Enter marks of the student (-1 for absent student)100

Enter Student name
E
Enter Roll No.5
Enter marks of the student (-1 for absent student)20

Enter Student name
F
Enter Roll No.6
Enter marks of the student (-1 for absent student)30

Enter Student name
G
Enter Roll No.7
Enter marks of the student (-1 for absent student)80

MENU:-
Enter 1 for displaying the result
Enter 2 for Average of the class
Enter 3 for Highest marks of the class
Enter 4 for Lowest marks of the class
Enter 5 for Absent students of the class
Enter 6 for Frequency of the marks1

Name of the Student: A
Roll No.: 1
Marks: 10

Name of the Student: B
Roll No.: 2
Marks: 20

Name of the Student: C
Roll No.: 3
Marks: 30

Name of the Student: D
Roll No.: 4
Marks: 100

Name of the Student: E
Roll No.: 5
Marks: 20

Name of the Student: F
Roll No.: 6
Marks: 30

Name of the Student: G
Roll No.: 7
Marks: 80

Do you want other information? (0 for no/1 for yes)
1

MENU:-
Enter 1 for displaying the result
Enter 2 for Average of the class
Enter 3 for Highest marks of the class
Enter 4 for Lowest marks of the class
Enter 5 for Absent students of the class
Enter 6 for Frequency of the marks2

Average of the class is 41.4286

Do you want other information? (0 for no/1 for yes)
1

MENU:-
Enter 1 for displaying the result
Enter 2 for Average of the class
Enter 3 for Highest marks of the class
Enter 4 for Lowest marks of the class
Enter 5 for Absent students of the class
Enter 6 for Frequency of the marks3

Highest marks: 100

Do you want other information? (0 for no/1 for yes)
1

MENU:-
Enter 1 for displaying the result
Enter 2 for Average of the class
Enter 3 for Highest marks of the class
Enter 4 for Lowest marks of the class
Enter 5 for Absent students of the class
Enter 6 for Frequency of the marks4

Lowest marks: 10

Do you want other information? (0 for no/1 for yes)
1

MENU:-
Enter 1 for displaying the result
Enter 2 for Average of the class
Enter 3 for Highest marks of the class
Enter 4 for Lowest marks of the class
Enter 5 for Absent students of the class
Enter 6 for Frequency of the marks5

No. of absent students : 0

Do you want other information? (0 for no/1 for yes)
1

MENU:-
Enter 1 for displaying the result
Enter 2 for Average of the class
Enter 3 for Highest marks of the class
Enter 4 for Lowest marks of the class
Enter 5 for Absent students of the class
Enter 6 for Frequency of the marks6

Frequency of marks obtained by maximum students:-20 - 2
Do you want other information? (0 for no/1 for yes)
0
 */


//OUTPUT FOR TEST CASE 2
/*
 *Enter number of student
7
Enter the details of the student:-

Enter Student name
A
Enter Roll No.1
Enter marks of the student (-1 for absent student)10

Enter Student name
B
Enter Roll No.2
Enter marks of the student (-1 for absent student)-1

Enter Student name
C
Enter Roll No.3
Enter marks of the student (-1 for absent student)30

Enter Student name
D
Enter Roll No.4
Enter marks of the student (-1 for absent student)100

Enter Student name
E
Enter Roll No.5
Enter marks of the student (-1 for absent student)30

Enter Student name
F
Enter Roll No.6
Enter marks of the student (-1 for absent student)-1

Enter Student name
G
Enter Roll No.7
Enter marks of the student (-1 for absent student)-1

MENU:-
Enter 1 for displaying the result
Enter 2 for Average of the class
Enter 3 for Highest marks of the class
Enter 4 for Lowest marks of the class
Enter 5 for Absent students of the class
Enter 6 for Frequency of the marks1

Name of the Student: A
Roll No.: 1
Marks: 10

Name of the Student: B
Roll No.: 2
Marks: Absent

Name of the Student: C
Roll No.: 3
Marks: 30

Name of the Student: D
Roll No.: 4
Marks: 100

Name of the Student: E
Roll No.: 5
Marks: 30

Name of the Student: F
Roll No.: 6
Marks: Absent

Name of the Student: G
Roll No.: 7
Marks: Absent

Do you want other information? (0 for no/1 for yes)
1

MENU:-
Enter 1 for displaying the result
Enter 2 for Average of the class
Enter 3 for Highest marks of the class
Enter 4 for Lowest marks of the class
Enter 5 for Absent students of the class
Enter 6 for Frequency of the marks2

Average of the class is 42.5

Do you want other information? (0 for no/1 for yes)
1

MENU:-
Enter 1 for displaying the result
Enter 2 for Average of the class
Enter 3 for Highest marks of the class
Enter 4 for Lowest marks of the class
Enter 5 for Absent students of the class
Enter 6 for Frequency of the marks3

Highest marks: 100

Do you want other information? (0 for no/1 for yes)
1

MENU:-
Enter 1 for displaying the result
Enter 2 for Average of the class
Enter 3 for Highest marks of the class
Enter 4 for Lowest marks of the class
Enter 5 for Absent students of the class
Enter 6 for Frequency of the marks4

Lowest marks: 10

Do you want other information? (0 for no/1 for yes)
1

MENU:-
Enter 1 for displaying the result
Enter 2 for Average of the class
Enter 3 for Highest marks of the class
Enter 4 for Lowest marks of the class
Enter 5 for Absent students of the class
Enter 6 for Frequency of the marks5

No. of absent students : 3

Do you want other information? (0 for no/1 for yes)
1

MENU:-
Enter 1 for displaying the result
Enter 2 for Average of the class
Enter 3 for Highest marks of the class
Enter 4 for Lowest marks of the class
Enter 5 for Absent students of the class
Enter 6 for Frequency of the marks6

Frequency of marks obtained by maximum students:-30 - 2
Do you want other information? (0 for no/1 for yes)
0

 *
 *
 */








