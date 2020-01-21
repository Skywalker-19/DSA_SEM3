//============================================================================
// Name        : matrix.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Matrix
{
	int m,n;
	int m1[10][10];
    public :
	void read();
	void display();
	int upper();
	Matrix transpose();
	int sumdia();
	Matrix add(Matrix m2);
	Matrix subtract(Matrix m2);
	Matrix multi(Matrix m2);
	int getRows();
	void saddle();
	};


void Matrix::read()
{
	cout<<"Enter number of rows"<<endl;
	cin>>m;
	cout<<"Enter number of columns"<<endl;
	cin>>n;
	int i,j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			m1[i][j]=0;
		}
	}
	if(m==0 || n==0)
	{
		cout<<"THE NO. OF ROWS/COLUMNS SHOULD BE GREATER THAN 0"<<endl;
	}
	else
	{
		cout<<"Enter the elements of matrix"<<endl;
	for(i=0;i<m;i++)
	  {
		for(j=0;j<n;j++)
		{
			cout<<"Element at "<<i<<" row and "<<j<<" column :- ";
			cin>>m1[i][j];
		}
	  }
    }
}

void Matrix::display()
{
	cout<<"The elements of matrix are:-"<<endl;
	for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<m1[i][j]<<" ";
			}
			cout<<" "<<endl;
		}
}

int Matrix::upper()
{
	int i,j,k;
	if(m!=n)
	{
		return -1;
	}
	else
	{
		k=1;
		for(i=1;i<m;i++)
		{
			for(j=0;j<i;j++)
			{
				if(m1[i][j]!=0)
				{
					k=0;
					break;
				}
			}
		}
		return k;
	}
}

Matrix Matrix::transpose()
{
	Matrix m2;
	m2.m=n;
	m2.n=m;
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		  m2.m1[j][i]=m1[i][j];
	    }
	}
return m2;
}

int Matrix::sumdia()
{
	int i,s=0;
	    if(m!=n)
		{
			return -1;
		}
		else
		{
	      for(i=0;i<m;i++)
	      {
	    	 s=s+m1[i][i];
	      }
	      return s;
		}
}

Matrix Matrix::add(Matrix m2)
{
	Matrix m3;
	m3.m=m;
	m3.n=n;
    if(m!=m2.m || n!=m2.n)
    {
    	m3.m=0;
    	return m3;
    }
    else
    {
	int i=0;
	int j=0;

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			m3.m1[i][j]=m2.m1[i][j]+m1[i][j];
		}
	}
	return m3;
    }
}

Matrix Matrix::subtract(Matrix m2)
{
	Matrix m3;
	m3.m=m;
	m3.n=n;
    if(m!=m2.m || n!=m2.n)
    {
    	m3.m=0;
    	return m3;
    }
    else
    {
	int i=0;
	int j=0;

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			m3.m1[i][j]=m2.m1[i][j]-m1[i][j];
		}
	}
	return m3;
    }
}

Matrix Matrix::multi(Matrix m2)
{
	Matrix m3;
	m3.m=m;
	m3.n=m2.n;
    if(n!=m2.m)
    {
    	m3.m=0;
    	cout<<m3.m;
    }
    else
    {
	int i=0;
	int j=0;
	int k=0;

	for(k=0;k<m;k++)
	{
	for(i=0;i<m2.n;i++)
	  {
		m3.m1[k][i]=0;
		for(j=0;j<n;j++)
		{

              m3.m1[k][i]=m3.m1[k][i]+(m1[k][j]*m2.m1[j][i]);
		}
	  }
    }
    }
	return m3;
}

void Matrix::saddle()
{
	int i,j,k,t,u,f=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		  t=m1[i][j];  u=m1[i][j];
		for(k=0;k<n;k++)
		{
			if(m1[i][k]< t)
			{t=m1[i][k];}
			if(m1[k][j]>t)
			{u=m1[k][j];}
		}
		if(u==t && t==m1[i][j] && u==m1[i][j])
		{
			cout<<"Saddle number - "<<t<<endl;
		    f=1;
			break;
		}
		if(f==1){break;}
        }
		if(f==1){break;}
   }
	if(f==0)
	{cout<<"No Saddle number present"<<endl;}
}


int Matrix::getRows()
{
	if(m==0 || n==0)
	{return 0;}
	else
	{return 1;}
}

int main()
{
	int c=0; int k=0;
	Matrix obj,o3,o4;
	for(; ;)
	{
	cout<<"............Matrix Operations.........."<<endl;
	cout<<"Enter 1 to read MATRIX from user"<<endl;
	cout<<"Enter 2 to display MATRIX to user"<<endl;
	cout<<"Enter 3 to check whether matrix is UPPER TRIANGULAR MATRIX"<<endl;
	cout<<"Enter 4 to display the TRANSPOSE OF A MATRIX"<<endl;
	cout<<"Enter 5 to calculate the SUM OF DIAGNOL ELEMENTS OF MATRIX"<<endl;
	cout<<"Enter 6 to find the SADDLE NUMBER IN THE MATRIX"<<endl;
	cout<<"Enter 7 to perform ADDITION OF TWO MATRICES"<<endl;
	cout<<"Enter 8 to perform SUBTRACTION OF TWO MATRICES"<<endl;
	cout<<"Enter 9 to perform MULTIPLICATION OF TWO MATRICES"<<endl;
	cin>>c;
	int g=0;
	switch(c)
	{
	case 1: obj.read();break;

	case 2: obj.display();break;

	case 3: k=obj.upper();
	        if(k==-1)
	        {cout<<"NOT A SQUARE MATRIX HENCE CAN'T CALCULATE"<<endl;
	        break;
	        }
	        else if(k==1){cout<<"MATRIX IS UPPER TRIANGULAR MATRIX"<<endl;}
	        else if(k==0){cout<<"MATRIX IS NOT UPPER TRIANGULAR MATRIX"<<endl;}
	        break;

	case 4: Matrix o2;
		    o2=obj.transpose();
	        o2.display();
	        break;

	case 5: k=obj.sumdia();
	        if(k==-1)
		    {
	          cout<<"NOT A SQUARE MATRIX HENCE CAN'T CALCULATE"<<endl;
		      break;
		    }
	        else{ cout<<"Sum of diagnol elements is "<<k<<endl;}
	        break;

	case 6:   obj.saddle(); break;

	case 7:
		   cout<<"Enter elements of 1st Matrix"<<endl;
	       obj.read();
	       cout<<"Enter elements of 2nd Matrix"<<endl;
	       o3.read();
	       o4=obj.add(o3);
           g=o4.getRows();
	       if(g==0)
	       {
	    	   cout<<"No. of rows/columns of the two matrices are not equal hence cannot calculate"<<endl;
	       }
	       else
	       { o4.display();}
	       break;

	case 8:
		       cout<<"Enter elements of 1st Matrix"<<endl;
			   obj.read();
			   cout<<"Enter elements of 2nd Matrix"<<endl;
		       o3.read();
		       o4=obj.subtract(o3);
		       g=o4.getRows();
		       if(g==0)
		       {
		    	  cout<<"No. of rows/columns of the two matrices are not equal hence cannot calculate"<<endl;
		       }
		       else
		       { o4.display();}
		       break;

	case 9:
		       cout<<"Enter elements of 1st Matrix"<<endl;
		       obj.read();
			   cout<<"Enter elements of 2nd Matrix"<<endl;
			   o3.read();
			   o4=obj.multi(o3);
			   g=o4.getRows();
			   if(g==0)
			   {
		         cout<<"No. of columns of 1st matrix is not equal to the rows of the second matrix hence cannot calculate"<<endl;
		       }
			   else
		       { o4.display();}
			   break;

	default:  cout<<"PLease enter choice from the above menu"<<endl;
	          k=1;
	 }

	if(k==1)
	{continue;}
	if(k==-1)
	{
		cout<<"Enter 1 if you want to accept another matrix else enter 0 if you want to continue with same matrix"<<endl;
		cin>>c;
		if(c==1)
		{obj.read();}
	}
	k=0;
	cout<<"DO YOU WANT TO PERFORM ANY OTHER OPERATION?(ENTER 0 FOR NO/1 FOR YES)"<<endl;
	cin>>c;
	if(c==0){break;}
	}

	return 0;
}



//OUTPUT
/*
 * 1. M=N CASES.
 *
 * ............Matrix Operations..........
Enter 1 to read MATRIX from user
Enter 2 to display MATRIX to user
Enter 3 to check whether matrix is UPPER TRIANGULAR MATRIX
Enter 4 to display the TRANSPOSE OF A MATRIX
Enter 5 to calculate the SUM OF DIAGNOL ELEMENTS OF MATRIX
Enter 6 to find the SADDLE NUMBER IN THE MATRIX
Enter 7 to perform ADDITION OF TWO MATRICES
Enter 8 to perform SUBTRACTION OF TWO MATRICES
Enter 9 to perform MULTIPLICATION OF TWO MATRICES
1
Enter number of rows
3
Enter number of columns
3
Enter the elements of matrix
Element at 0 row and 0 column :- 1
Element at 0 row and 1 column :- 2
Element at 0 row and 2 column :- 3
Element at 1 row and 0 column :- 4
Element at 1 row and 1 column :- 5
Element at 1 row and 2 column :- 6
Element at 2 row and 0 column :- 7
Element at 2 row and 1 column :- 8
Element at 2 row and 2 column :- 9
DO YOU WANT TO PERFORM ANY OTHER OPERATION?(ENTER 0 FOR NO/1 FOR YES)
1
............Matrix Operations..........
Enter 1 to read MATRIX from user
Enter 2 to display MATRIX to user
Enter 3 to check whether matrix is UPPER TRIANGULAR MATRIX
Enter 4 to display the TRANSPOSE OF A MATRIX
Enter 5 to calculate the SUM OF DIAGNOL ELEMENTS OF MATRIX
Enter 6 to find the SADDLE NUMBER IN THE MATRIX
Enter 7 to perform ADDITION OF TWO MATRICES
Enter 8 to perform SUBTRACTION OF TWO MATRICES
Enter 9 to perform MULTIPLICATION OF TWO MATRICES
2
The elements of matrix are:-
1 2 3
4 5 6
7 8 9
DO YOU WANT TO PERFORM ANY OTHER OPERATION?(ENTER 0 FOR NO/1 FOR YES)
1
............Matrix Operations..........
Enter 1 to read MATRIX from user
Enter 2 to display MATRIX to user
Enter 3 to check whether matrix is UPPER TRIANGULAR MATRIX
Enter 4 to display the TRANSPOSE OF A MATRIX
Enter 5 to calculate the SUM OF DIAGNOL ELEMENTS OF MATRIX
Enter 6 to find the SADDLE NUMBER IN THE MATRIX
Enter 7 to perform ADDITION OF TWO MATRICES
Enter 8 to perform SUBTRACTION OF TWO MATRICES
Enter 9 to perform MULTIPLICATION OF TWO MATRICES
3
MATRIX IS NOT UPPER TRIANGULAR MATRIX
DO YOU WANT TO PERFORM ANY OTHER OPERATION?(ENTER 0 FOR NO/1 FOR YES)
1
............Matrix Operations..........
Enter 1 to read MATRIX from user
Enter 2 to display MATRIX to user
Enter 3 to check whether matrix is UPPER TRIANGULAR MATRIX
Enter 4 to display the TRANSPOSE OF A MATRIX
Enter 5 to calculate the SUM OF DIAGNOL ELEMENTS OF MATRIX
Enter 6 to find the SADDLE NUMBER IN THE MATRIX
Enter 7 to perform ADDITION OF TWO MATRICES
Enter 8 to perform SUBTRACTION OF TWO MATRICES
Enter 9 to perform MULTIPLICATION OF TWO MATRICES
4
The elements of matrix are:-
1 4 7
2 5 8
3 6 9
DO YOU WANT TO PERFORM ANY OTHER OPERATION?(ENTER 0 FOR NO/1 FOR YES)
1
............Matrix Operations..........
Enter 1 to read MATRIX from user
Enter 2 to display MATRIX to user
Enter 3 to check whether matrix is UPPER TRIANGULAR MATRIX
Enter 4 to display the TRANSPOSE OF A MATRIX
Enter 5 to calculate the SUM OF DIAGNOL ELEMENTS OF MATRIX
Enter 6 to find the SADDLE NUMBER IN THE MATRIX
Enter 7 to perform ADDITION OF TWO MATRICES
Enter 8 to perform SUBTRACTION OF TWO MATRICES
Enter 9 to perform MULTIPLICATION OF TWO MATRICES
5
Sum of diagnol elements is 15
DO YOU WANT TO PERFORM ANY OTHER OPERATION?(ENTER 0 FOR NO/1 FOR YES)
1
............Matrix Operations..........
Enter 1 to read MATRIX from user
Enter 2 to display MATRIX to user
Enter 3 to check whether matrix is UPPER TRIANGULAR MATRIX
Enter 4 to display the TRANSPOSE OF A MATRIX
Enter 5 to calculate the SUM OF DIAGNOL ELEMENTS OF MATRIX
Enter 6 to find the SADDLE NUMBER IN THE MATRIX
Enter 7 to perform ADDITION OF TWO MATRICES
Enter 8 to perform SUBTRACTION OF TWO MATRICES
Enter 9 to perform MULTIPLICATION OF TWO MATRICES
6
Saddle number - 7
DO YOU WANT TO PERFORM ANY OTHER OPERATION?(ENTER 0 FOR NO/1 FOR YES)
1
............Matrix Operations..........
Enter 1 to read MATRIX from user
Enter 2 to display MATRIX to user
Enter 3 to check whether matrix is UPPER TRIANGULAR MATRIX
Enter 4 to display the TRANSPOSE OF A MATRIX
Enter 5 to calculate the SUM OF DIAGNOL ELEMENTS OF MATRIX
Enter 6 to find the SADDLE NUMBER IN THE MATRIX
Enter 7 to perform ADDITION OF TWO MATRICES
Enter 8 to perform SUBTRACTION OF TWO MATRICES
Enter 9 to perform MULTIPLICATION OF TWO MATRICES
7
Enter elements of 1st Matrix
Enter number of rows
2
Enter number of columns
2
Enter the elements of matrix
Element at 0 row and 0 column :- 1
Element at 0 row and 1 column :- 2
Element at 1 row and 0 column :- 3
Element at 1 row and 1 column :- 4
Enter elements of 2nd Matrix
Enter number of rows
2
Enter number of columns
2
Enter the elements of matrix
Element at 0 row and 0 column :- 5
Element at 0 row and 1 column :- 6
Element at 1 row and 0 column :- 7
Element at 1 row and 1 column :- 8
The elements of matrix are:-
6 8
10 12
DO YOU WANT TO PERFORM ANY OTHER OPERATION?(ENTER 0 FOR NO/1 FOR YES)
1
............Matrix Operations..........
Enter 1 to read MATRIX from user
Enter 2 to display MATRIX to user
Enter 3 to check whether matrix is UPPER TRIANGULAR MATRIX
Enter 4 to display the TRANSPOSE OF A MATRIX
Enter 5 to calculate the SUM OF DIAGNOL ELEMENTS OF MATRIX
Enter 6 to find the SADDLE NUMBER IN THE MATRIX
Enter 7 to perform ADDITION OF TWO MATRICES
Enter 8 to perform SUBTRACTION OF TWO MATRICES
Enter 9 to perform MULTIPLICATION OF TWO MATRICES
8
Enter elements of 1st Matrix
Enter number of rows
2
Enter number of columns
2
Enter the elements of matrix
Element at 0 row and 0 column :- 5
Element at 0 row and 1 column :- 6
Element at 1 row and 0 column :- 7
Element at 1 row and 1 column :- 8
Enter elements of 2nd Matrix
Enter number of rows
2
Enter number of columns
2
Enter the elements of matrix
Element at 0 row and 0 column :- 1
Element at 0 row and 1 column :- 2
Element at 1 row and 0 column :- 3
Element at 1 row and 1 column :- 4
The elements of matrix are:-
-4 -4
-4 -4
DO YOU WANT TO PERFORM ANY OTHER OPERATION?(ENTER 0 FOR NO/1 FOR YES)
1
............Matrix Operations..........
Enter 1 to read MATRIX from user
Enter 2 to display MATRIX to user
Enter 3 to check whether matrix is UPPER TRIANGULAR MATRIX
Enter 4 to display the TRANSPOSE OF A MATRIX
Enter 5 to calculate the SUM OF DIAGNOL ELEMENTS OF MATRIX
Enter 6 to find the SADDLE NUMBER IN THE MATRIX
Enter 7 to perform ADDITION OF TWO MATRICES
Enter 8 to perform SUBTRACTION OF TWO MATRICES
Enter 9 to perform MULTIPLICATION OF TWO MATRICES
9
Enter elements of 1st Matrix
Enter number of rows
2
Enter number of columns
2
Enter the elements of matrix
Element at 0 row and 0 column :- 1
Element at 0 row and 1 column :- 2
Element at 1 row and 0 column :- 3
Element at 1 row and 1 column :- 4
Enter elements of 2nd Matrix
Enter number of rows
2
Enter number of columns
2
Enter the elements of matrix
Element at 0 row and 0 column :- 1
Element at 0 row and 1 column :- 2
Element at 1 row and 0 column :- 3
Element at 1 row and 1 column :- 4
The elements of matrix are:-
7 10
15 22
DO YOU WANT TO PERFORM ANY OTHER OPERATION?(ENTER 0 FOR NO/1 FOR YES)
0


2. M!=N CASES

 *
 * ............Matrix Operations..........
Enter 1 to read MATRIX from user
Enter 2 to display MATRIX to user
Enter 3 to check whether matrix is UPPER TRIANGULAR MATRIX
Enter 4 to display the TRANSPOSE OF A MATRIX
Enter 5 to calculate the SUM OF DIAGNOL ELEMENTS OF MATRIX
Enter 6 to find the SADDLE NUMBER IN THE MATRIX
Enter 7 to perform ADDITION OF TWO MATRICES
Enter 8 to perform SUBTRACTION OF TWO MATRICES
Enter 9 to perform MULTIPLICATION OF TWO MATRICES
1
Enter number of rows
2
Enter number of columns
3
Enter the elements of matrix
Element at 0 row and 0 column :- 1
Element at 0 row and 1 column :- 2
Element at 0 row and 2 column :- 3
Element at 1 row and 0 column :- 4
Element at 1 row and 1 column :- 5
Element at 1 row and 2 column :- 6
DO YOU WANT TO PERFORM ANY OTHER OPERATION?(ENTER 0 FOR NO/1 FOR YES)
1
............Matrix Operations..........
Enter 1 to read MATRIX from user
Enter 2 to display MATRIX to user
Enter 3 to check whether matrix is UPPER TRIANGULAR MATRIX
Enter 4 to display the TRANSPOSE OF A MATRIX
Enter 5 to calculate the SUM OF DIAGNOL ELEMENTS OF MATRIX
Enter 6 to find the SADDLE NUMBER IN THE MATRIX
Enter 7 to perform ADDITION OF TWO MATRICES
Enter 8 to perform SUBTRACTION OF TWO MATRICES
Enter 9 to perform MULTIPLICATION OF TWO MATRICES
2
The elements of matrix are:-
1 2 3
4 5 6
DO YOU WANT TO PERFORM ANY OTHER OPERATION?(ENTER 0 FOR NO/1 FOR YES)
1
............Matrix Operations..........
Enter 1 to read MATRIX from user
Enter 2 to display MATRIX to user
Enter 3 to check whether matrix is UPPER TRIANGULAR MATRIX
Enter 4 to display the TRANSPOSE OF A MATRIX
Enter 5 to calculate the SUM OF DIAGNOL ELEMENTS OF MATRIX
Enter 6 to find the SADDLE NUMBER IN THE MATRIX
Enter 7 to perform ADDITION OF TWO MATRICES
Enter 8 to perform SUBTRACTION OF TWO MATRICES
Enter 9 to perform MULTIPLICATION OF TWO MATRICES
3
NOT A SQUARE MATRIX HENCE CAN'T CALCULATE
Enter 1 if you want to accept another matrix else enter 0 if you want to continue with same matrix
0
DO YOU WANT TO PERFORM ANY OTHER OPERATION?(ENTER 0 FOR NO/1 FOR YES)
1
............Matrix Operations..........
Enter 1 to read MATRIX from user
Enter 2 to display MATRIX to user
Enter 3 to check whether matrix is UPPER TRIANGULAR MATRIX
Enter 4 to display the TRANSPOSE OF A MATRIX
Enter 5 to calculate the SUM OF DIAGNOL ELEMENTS OF MATRIX
Enter 6 to find the SADDLE NUMBER IN THE MATRIX
Enter 7 to perform ADDITION OF TWO MATRICES
Enter 8 to perform SUBTRACTION OF TWO MATRICES
Enter 9 to perform MULTIPLICATION OF TWO MATRICES
4
The elements of matrix are:-
1 4
2 5
3 6
DO YOU WANT TO PERFORM ANY OTHER OPERATION?(ENTER 0 FOR NO/1 FOR YES)
1
............Matrix Operations..........
Enter 1 to read MATRIX from user
Enter 2 to display MATRIX to user
Enter 3 to check whether matrix is UPPER TRIANGULAR MATRIX
Enter 4 to display the TRANSPOSE OF A MATRIX
Enter 5 to calculate the SUM OF DIAGNOL ELEMENTS OF MATRIX
Enter 6 to find the SADDLE NUMBER IN THE MATRIX
Enter 7 to perform ADDITION OF TWO MATRICES
Enter 8 to perform SUBTRACTION OF TWO MATRICES
Enter 9 to perform MULTIPLICATION OF TWO MATRICES
5
NOT A SQUARE MATRIX HENCE CAN'T CALCULATE
Enter 1 if you want to accept another matrix else enter 0 if you want to continue with same matrix
0
DO YOU WANT TO PERFORM ANY OTHER OPERATION?(ENTER 0 FOR NO/1 FOR YES)
1
............Matrix Operations..........
Enter 1 to read MATRIX from user
Enter 2 to display MATRIX to user
Enter 3 to check whether matrix is UPPER TRIANGULAR MATRIX
Enter 4 to display the TRANSPOSE OF A MATRIX
Enter 5 to calculate the SUM OF DIAGNOL ELEMENTS OF MATRIX
Enter 6 to find the SADDLE NUMBER IN THE MATRIX
Enter 7 to perform ADDITION OF TWO MATRICES
Enter 8 to perform SUBTRACTION OF TWO MATRICES
Enter 9 to perform MULTIPLICATION OF TWO MATRICES
6
Saddle number - 4
DO YOU WANT TO PERFORM ANY OTHER OPERATION?(ENTER 0 FOR NO/1 FOR YES)
1
............Matrix Operations..........
Enter 1 to read MATRIX from user
Enter 2 to display MATRIX to user
Enter 3 to check whether matrix is UPPER TRIANGULAR MATRIX
Enter 4 to display the TRANSPOSE OF A MATRIX
Enter 5 to calculate the SUM OF DIAGNOL ELEMENTS OF MATRIX
Enter 6 to find the SADDLE NUMBER IN THE MATRIX
Enter 7 to perform ADDITION OF TWO MATRICES
Enter 8 to perform SUBTRACTION OF TWO MATRICES
Enter 9 to perform MULTIPLICATION OF TWO MATRICES
7
Enter elements of 1st Matrix
Enter number of rows
2
Enter number of columns
3
Enter the elements of matrix
Element at 0 row and 0 column :- 1
Element at 0 row and 1 column :- 2
Element at 0 row and 2 column :- 3
Element at 1 row and 0 column :- 4
Element at 1 row and 1 column :- 5
Element at 1 row and 2 column :- 6
Enter elements of 2nd Matrix
Enter number of rows
1
Enter number of columns
2
Enter the elements of matrix
Element at 0 row and 0 column :- 1
Element at 0 row and 1 column :- 2
No. of rows/columns of the two matrices are not equal hence cannot calculate
DO YOU WANT TO PERFORM ANY OTHER OPERATION?(ENTER 0 FOR NO/1 FOR YES)
1
............Matrix Operations..........
Enter 1 to read MATRIX from user
Enter 2 to display MATRIX to user
Enter 3 to check whether matrix is UPPER TRIANGULAR MATRIX
Enter 4 to display the TRANSPOSE OF A MATRIX
Enter 5 to calculate the SUM OF DIAGNOL ELEMENTS OF MATRIX
Enter 6 to find the SADDLE NUMBER IN THE MATRIX
Enter 7 to perform ADDITION OF TWO MATRICES
Enter 8 to perform SUBTRACTION OF TWO MATRICES
Enter 9 to perform MULTIPLICATION OF TWO MATRICES
8
Enter elements of 1st Matrix
Enter number of rows
2
Enter number of columns
3
Enter the elements of matrix
Element at 0 row and 0 column :- 1
Element at 0 row and 1 column :- 2
Element at 0 row and 2 column :- 3
Element at 1 row and 0 column :- 4
Element at 1 row and 1 column :- 5
Element at 1 row and 2 column :- 6
Enter elements of 2nd Matrix
Enter number of rows
2
Enter number of columns
3
Enter the elements of matrix
Element at 0 row and 0 column :- 2
Element at 0 row and 1 column :- 3
Element at 0 row and 2 column :- 4
Element at 1 row and 0 column :- 5
Element at 1 row and 1 column :- 6
Element at 1 row and 2 column :- 7
The elements of matrix are:-
1 1 1
1 1 1
DO YOU WANT TO PERFORM ANY OTHER OPERATION?(ENTER 0 FOR NO/1 FOR YES)
1
............Matrix Operations..........
Enter 1 to read MATRIX from user
Enter 2 to display MATRIX to user
Enter 3 to check whether matrix is UPPER TRIANGULAR MATRIX
Enter 4 to display the TRANSPOSE OF A MATRIX
Enter 5 to calculate the SUM OF DIAGNOL ELEMENTS OF MATRIX
Enter 6 to find the SADDLE NUMBER IN THE MATRIX
Enter 7 to perform ADDITION OF TWO MATRICES
Enter 8 to perform SUBTRACTION OF TWO MATRICES
Enter 9 to perform MULTIPLICATION OF TWO MATRICES
9
Enter elements of 1st Matrix
Enter number of rows
2
Enter number of columns
3
Enter the elements of matrix
Element at 0 row and 0 column :- 2
Element at 0 row and 1 column :- 3
Element at 0 row and 2 column :- 1
Element at 1 row and 0 column :- 4
Element at 1 row and 1 column :- 5
Element at 1 row and 2 column :- 6
Enter elements of 2nd Matrix
Enter number of rows
1
Enter number of columns
2
Enter the elements of matrix
Element at 0 row and 0 column :- 1
Element at 0 row and 1 column :- 3
0No. of columns of 1st matrix is not equal to the rows of the second matrix hence cannot calculate
DO YOU WANT TO PERFORM ANY OTHER OPERATION?(ENTER 0 FOR NO/1 FOR YES)
1
............Matrix Operations..........
Enter 1 to read MATRIX from user
Enter 2 to display MATRIX to user
Enter 3 to check whether matrix is UPPER TRIANGULAR MATRIX
Enter 4 to display the TRANSPOSE OF A MATRIX
Enter 5 to calculate the SUM OF DIAGNOL ELEMENTS OF MATRIX
Enter 6 to find the SADDLE NUMBER IN THE MATRIX
Enter 7 to perform ADDITION OF TWO MATRICES
Enter 8 to perform SUBTRACTION OF TWO MATRICES
Enter 9 to perform MULTIPLICATION OF TWO MATRICES
9
Enter elements of 1st Matrix
Enter number of rows
2
Enter number of columns
3
Enter the elements of matrix
Element at 0 row and 0 column :- 1
Element at 0 row and 1 column :- 2
Element at 0 row and 2 column :- 3
Element at 1 row and 0 column :- 4
Element at 1 row and 1 column :- 5
Element at 1 row and 2 column :- 6
Enter elements of 2nd Matrix
Enter number of rows
3
Enter number of columns
2
Enter the elements of matrix
Element at 0 row and 0 column :- 1
Element at 0 row and 1 column :- 2
Element at 1 row and 0 column :- 3
Element at 1 row and 1 column :- 4
Element at 2 row and 0 column :- 5
Element at 2 row and 1 column :- 6
The elements of matrix are:-
22 28
49 64
DO YOU WANT TO PERFORM ANY OTHER OPERATION?(ENTER 0 FOR NO/1 FOR YES)
0

 *
 */

