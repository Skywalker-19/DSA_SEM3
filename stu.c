/*
 * stu.c
 *
 *  Created on: Jun 17, 2019
 *      Author: SE
 */
#include <stdio.h>

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
			printf("\nEnter Student name");
			scanf("%s",s[i].name);
			printf("Enter Roll No.");
			scanf("%d",&s[i].roll);
			printf("Enter marks of the student (-1 for absent student)");
			scanf("%f",&s[i].marks);
		}

}
void display()
{
	int i=0;
	for(i=0;i<n;i++)
	{
	printf("\nName of the Student: %s",s[i].name);
	printf("\nRoll No.: %d",s[i].roll);
	if(s[i].marks==-1)
	{
		printf("\nMarks: Absent");
		continue;
	}
	printf("\nMarks: %f",s[i].marks);
	}
}
void avg()
{
	//Average score
	int i=0;
	float sum=0;
		float avg=0;
		for(i=0;i<n;i++)
		{
			if(s[i].marks==-1)
			{continue;}
			sum=sum+s[i].marks;
		}
		avg=sum/n;
		printf("\nAverage of the class is %f",avg);
}
void highest()
{
	float t=s[0].marks;
    float g=0; int i=0;
	for(i=0;i<n;i++)
	{
		if(s[i].marks==-1)
					{continue;}
			if(s[i].marks>t)
			{
				g=t;
				t=s[i].marks;
			s[i].marks=g;
			}
	}
			printf("\nHighest marks: %f",t);
}

	void lowest()
	{

		float t=s[0].marks;
	    float g=0; int i=0;
		for(i=0;i<n;i++)
		{
			if(s[i].marks==-1)
			{continue;}
				if(s[i].marks<t)
				{
					g=t;
					t=s[i].marks;
				    s[i].marks=g;
		        }
		}
				printf("\nLowest marks: %f",t);
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
		printf("\nNo. of absent students : %d",c);

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
					s[j].marks=-1;
				}
			}
			}
		}
		printf("\nFrequency of marks:-");
		for( i=0;i<n;i++)
		{
			if(s[i].marks>=0)
			printf("\n%f - %d",s[i].marks,arr[i]);
		}
	}


int main()
{
    int ch=0;
    int f=0;
	printf("Enter number of student");
	scanf("%d",&n);
	printf("Enter the details of the student:-");
	read();

	for(; ;)
	{
		f=0;
		ch=0;
	printf("\nMENU:-");
	printf("\nEnter 1 for displaying the result");
	printf("\nEnter 2 for Average of the class");
	printf("\nEnter 3 for Highest marks of the class");
	printf("\nEnter 4 for Lowest marks of the class");
	printf("\nEnter 5 for Absent students of the class");
	printf("\nEnter 6 for Frequency of the marks");
	scanf("%d",&ch);

	switch(ch)
	{
	case 1:display();break;
	case 2:avg();break;
	case 3:highest();break;
	case 4:lowest();break;
	case 5:absent();break;
	case 6:frequency();break;
	default: printf("Enter an number from the above"); f=1;
	}

	if(f==1)
	{
		continue;
	}
	int g=0;
	printf("\nDo you want other information? (0 for no/1 for yes)");
	scanf("%d",&g);
	if(g==1)
	{
	continue;
	}
	else{break;}
}
	return 0;
}





