//============================================================================
// Name        : Sparse.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class Sparse
{
	int m,n,t;
	int mat[50][3];
public:
	void read();
	void display();
	int check(Sparse obj2);
	Sparse add(Sparse ob1);
	Sparse transpose();
};

void Sparse::read()
{
	cout<<"Enter number of rows"<<endl;
		cin>>m;
		cout<<"Enter number of columns"<<endl;
		cin>>n;
		int i,j;

		for(i=0;i<50;i++)
		{
			for(j=0;j<3;j++)
			{
				mat[i][j]=0;
			}
		}

		cout<<"Enter number of non zero numbers"<<endl;
		cin>>t;

		for(i=0;i<t;i++)
			{

			    cout<<"Enter details of "<<(i+1)<<" non zero element :-"<<endl;
				cout<<"Enter the row of element"<<endl;
				cin>>mat[i][0];
				cout<<"Enter the column of element"<<endl;
				cin>>mat[i][1];
				cout<<"Enter the value "<<endl;
				cin>>mat[i][2];
			}

}

void Sparse::display()
{
	cout<<"NO. OF ROWS :- "<<m<<endl;
	cout<<"NO. OF COLUMNS :- "<<n<<endl;
	cout<<"NO. OF NON ZERO ELEMENTS:- "<<t<<endl;
	cout<<" ROW   COLUMN   VALUE"<<endl;
	for(int i=0;i<t;i++)
	{
		cout<<"  "<<mat[i][0]<<"       "<<mat[i][1]<<"      "<<mat[i][2]<<endl;
	}
}

Sparse Sparse::add(Sparse ob1)
{
	Sparse ob2;
	ob2.m=m;
	ob2.n=n;
	int i,j,k,temp=0;

	for(i=0;i<50;i++)
	{
	   for(j=0;j<3;j++)
			{
			  ob2.mat[i][j]=0;
			}
	}

    k=0;
	for(i=0,j=0;i<t && j<ob1.t;)
	{
		if(mat[i][0]<ob1.mat[j][0])
		{
			ob2.mat[k][0]=mat[i][0];
			ob2.mat[k][1]=mat[i][1];
			ob2.mat[k][2]=mat[i][2];
			k++;
		i++;
		}
		else if(mat[i][0]>ob1.mat[j][0])
		{
			ob2.mat[k][0]=obj1.mat[j][0];
			ob2.mat[k][1]=obj1.mat[j][1];
			ob2.mat[k][2]=obj1.mat[j][2];
			k++;
		    j++;
		}
		else if(mat[i][0]==ob1.mat[j][0])
		{
			if(mat[i][1]<ob1.mat[j][1])
			{
				ob2.mat[k][0]=mat[i][0];
				ob2.mat[k][1]=mat[i][1];
				ob2.mat[k][2]=mat[i][2];
				k++;
				i++;
			}
			else if(mat[i][1]>ob1.mat[j][1])
			{
				ob2.mat[k][0]=ob1.mat[j][0];
				ob2.mat[k][1]=ob1.mat[j][1];
				ob2.mat[k][2]=ob1.mat[j][2];
				k++;
				j++;
			}
			else if(mat[i][1]==ob1.mat[j][1])
			{
				
				temp=mat[i][2] + ob1.mat[j][2];
				if(temp!=0)
				{
					ob2.mat[k][0]=mat[i][0];
				ob2.mat[k][1]=mat[i][1];
				ob2.mat[k][2]=temp;
				i++;
				j++;
				k++;
				}
				else
				{
					i++;
					j++;
				}
		    }
		}
	}
	for(;i<t;i++)
	{
		ob2.mat[k][0]=mat[i][0];
		ob2.mat[k][1]=mat[i][1];
		ob2.mat[k][2]=mat[i][2];
		k++;
	}
	for(;j<ob1.t;j++)
	{
		ob2.mat[k][0]=ob1.mat[j][0];
		ob2.mat[k][1]=ob1.mat[j][1];
		ob2.mat[k][2]=ob1.mat[j][2];
		k++;
	}
	ob2.t=k;
  return ob2;
}

Sparse Sparse::transpose()
{
	Sparse ob2;
	ob2.m=n;
	ob2.n=m;
	ob2.t=t;
	int rsize[t];
	int rstart[t];
	int i,k;
	for(i=0;i<50;i++)
	{
	   for(k=0;k<3;k++)
			{
			  ob2.mat[i][k]=0;
			}
	}
	for(i=0;i<t;i++)
	{
		rsize[i]=0;
		rstart[i]=0;
	}
	for(i=0;i<t;i++)
	{
		rsize[(mat[i][1])]=rsize[(mat[i][1])]+1;
	}
	for(i=1;i<n;i++)
	{
		rstart[i]=rstart[i-1]+rsize[i-1];
	}
	for(i=0;i<t;i++)
	{
		k=rstart[mat[i][1]];
		ob2.mat[k][0]=mat[i][1];
		ob2.mat[k][1]=mat[i][0];
	    ob2.mat[k][2]=mat[i][2];
	    rstart[k]++;
	}
	return ob2;
}

int Sparse::check(Sparse obj2)
{
	if(m==obj2.m && n==obj2.n)
	{return 1;}

	else
	{
		int k=0;

		for(int i=0;i<t;i++)
		{
			if(obj2.mat[i][0]>obj2.m || obj2.mat[i][1]>obj2.n || mat[i][0]>m || mat[i][1]>n)
			{k=-1;}
		}

	return k;
}
}

int main()
{
	int c,f=0; int k=0;
	Sparse obj,obj2,obj3;
	for(; ;)
	{
	cout<<"............Sparse Matrix Operations.........."<<endl;
	cout<<"Enter 1 to read MATRIX from user"<<endl;
	cout<<"Enter 2 to display MATRIX to user"<<endl;
	cout<<"Enter 3 to TRANPOSE THE MATRIX "<<endl;
	cout<<"Enter 4 to ADD TWO SPARSE MATRICES"<<endl;
	cin>>c;

		switch(c)
		{
		case 1: obj.read();break;

		case 2: obj.display();break;

		case 3:
			         /* for(; ; )
			          {
			        	  f=obj.check(obj2);
			            if(f==-1)
					       {
					    	   cout<<"No. of rows and columns of either element of matrices is exceeding the limit "<<endl;
					    	   	cout<<"Do you want to accept again?(0 for No/1 for Yes)";
					    	   	 cin>>f;
					    	   	if(f==0)
					    	   	{break;}
					    	   	else
					    	   	 { obj.read(); continue;}

					       }
			            else
			            {
			              obj3=obj.transpose();
		                  obj3.display();
		                  break;
			            }
			         }*/
			           obj3=obj.transpose();
					    obj3.display();
			          break;

		case 4:
		 for( ; ; )
		 {
			   cout<<"Enter element of 2nd Sparse Matrix"<<endl;
		       obj2.read();
		       f=obj.check(obj2);
		       if(f==0)
		       {
		    	   cout<<"No. of rows and columns of both matrices are not equal"<<endl;
		    	   cout<<"Do you want to accept again?(0 for No/1 for Yes)";
		    	   cin>>f;
		    	   if(f==0)
		    	   {break;}
		    	   else
		    	   {continue;}

		       }
		       else if(f==-1)
		       {
		    	   cout<<"No. of rows and columns of either element of matrices is exceeding the limit "<<endl;
		    	   	cout<<"Do you want to accept again?(0 for No/1 for Yes)";
		    	   	 cin>>f;
		    	   	if(f==0)
		    	   	{break;}
		    	   	else
		    	   	 {continue;}

		       }
		       else
		       {
		    	   obj3=obj.add(obj2);
		    	   obj3.display();
		    	   break;
		       }
		 }
		       break;

		default:  cout<<"Please enter choice from the above menu"<<endl;
			          k=1;
		}

			if(k==1)
			{continue;}
			k=0;
		     cout<<"DO YOU WANT TO PERFORM ANY OTHER OPERATION?(ENTER 0 FOR NO/1 FOR YES)"<<endl;
			 cin>>c;
			 if(c==0){break;}
    }
}


