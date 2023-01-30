#include<iostream>
using namespace std;
class Matrix
{
	int a[10][10],m,n;
	public:
		void inputmatrices();
		void outputmatrices();
		Matrix operator*(Matrix x);
};
void Matrix::inputmatrices()
{
	int i,j;
	cout<<"Enter order of matrix:";
	cin>>m>>n;
	cout<<"Enter matrix elements:";
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
}
void Matrix::outputmatrices()
{ 
	int i,j;
	for(i=0;i<m;i++)
	{ 
		for(j=0;j<n;j++)
		{
			cout<<a[i][j]<<"\t";
		}
        			cout<<endl; 

	}
}

Matrix Matrix::operator*(Matrix x)
{ 
	Matrix c;
	int i,j,k;
	if(n==x.m)
	{ 
		c.m=m;
		c.n=x.n;
		for(i=0;i<m;i++)
		{
			for(j=0;j<x.n;j++)
			{ 
				c.a[i][j]=0;
			
		
		for(k=0;k<m;k++)
		{
			c.a[i][j]+=a[i][k]*x.a[k][j];
		}}}
		return c; 
	}
	else
		cout<<"Multiplication is not possible.";
}
int main()
{ 
Matrix A,B,C;
cout<<"Enter matrix A order and elements:"<<endl;
A.inputmatrices();
cout<<"Enter matrix B order and elements:"<<endl;
B.inputmatrices();
C=A*B;
cout<<"Resulting matrix is:"<<endl;
C.outputmatrices();
return 0;
}