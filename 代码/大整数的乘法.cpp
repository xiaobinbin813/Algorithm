//���������˷����㷨
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
#define MAXN 40				//����λ��
void Left(int A[],int B[],int n)	//ȡA����ߣ���λ��n/2λ�ŵ�B�� 
{	int i;
	for (i=0;i<MAXN;i++)
		B[i]=0;
	for (i=n/2;i<=n;i++)
		B[i-n/2]=A[i];
}
void Right(int A[],int B[],int n)//ȡA���ұߣ���λ��n/2λ
{	int i;
	for (i=0;i<MAXN;i++)
		B[i]=0;
	for (i=0;i<n/2;i++)
		B[i]=A[i];
	B[i]='\0';
}
long Trans2to10(int A[])		//��������ת����ʮ������
{	int i;
	long s=A[0],x=1;
	for (i=1;i<MAXN;i++)
	{	x=2*x;
		s+=A[i]*x;
	}
	return s;
}
void Trans10to2(int x,int A[])	//��ʮ����ת���ɶ�������
{	int i,j=0;
	while (x>0)
	{	A[j]=x%2;	j++;
		x=x/2;
	}
	for (i=j;i<MAXN;i++)
		A[i]=0;
}
void disp(int A[])		//�Ӹ�λ����λ�����������A
{	int i;
	for (i=MAXN-1;i>=0;i--)
	    cout<<A[i];
	cout<<endl;
}
void MULT(int X[],int Y[],int Z[],int n) //��Z=X*Y
{	int i;
	long e,e1,e2,e3,e4;
	int A[MAXN],B[MAXN],C[MAXN],D[MAXN];
	int m1[MAXN],m2[MAXN],m3[MAXN],m4[MAXN];
	for (i=0;i<MAXN;i++)	//Z��ʼ��Ϊ0
		Z[i]=0;
	if (n==1)				//�ݹ����
	{	if (X[0]==1 && Y[0]==1)	Z[0]=1;
		else Z[0]=0;
	}
	else
	{	Left(X,A,n);		//AȡX�����n/2λ
		Right(X,B,n);		//BȡX���ұ�n/2λ;
		Left(Y,C,n);		//CȡY�����n/2λ;
		Right(Y,D,n);		//DȡY���ұ�n/2λ;
		MULT(A,C,m1,n/2);	//m1=AC
		MULT(A,D,m2,n/2);	//m2=AD
		MULT(B,C,m3,n/2);	//m3=BC
		MULT(B,D,m4,n/2);	//m4=DB
		e1=Trans2to10(m1);	//��m1ת����ʮ������e1
		e2=Trans2to10(m2);	//��m2ת����ʮ������e2
		e3=Trans2to10(m3);	//��m3ת����ʮ������e3
		e4=Trans2to10(m4);	//��m4ת����ʮ������e4
		e=e1*(int)pow(2,n)+(e2+e3)*(int)pow(2,n/2)+e4;
		Trans10to2(e,Z);	//��eת���ɶ�������Z
	}
}
void trans(char a[],int n,int A[])	//���ַ���aת��Ϊ��������A
{	int i;
	for (i=0;i<n;i++)
		A[i]=int(a[n-1-i]-'0');
	for (i=n;i<MAXN;i++)
		A[i]=0;
}
int main()
{	long e;
	char a[]="1010110010101";	//������������Ķ�������
	char b[]="1001001110101";
	int X[MAXN],Y[MAXN],Z[MAXN];
	int n=13;
	trans(a,n,X);			//��aת������������X
	trans(b,n,Y);			//��bת������������Y
	cout<<"X:";
	disp(X);	//���X
	cout<<"Y:"; disp(Y);	//���Y
	cout<<"Z=X*Y\n";
	MULT(X,Y,Z,n);		//��Z=X*Y
	cout<<"Z:  ";
	disp(Z);	//���Z
	e=Trans2to10(Z);		//��Zת����ʮ������e
	cout<<"Z��Ӧ��ʮ������:"<<e<<endl;
	cout<<"��֤��ȷ��:\n";

	long x,y,z;
	x=Trans2to10(X);		//��Xת����ʮ������x
	y=Trans2to10(Y);		//��Xת����ʮ������y
	cout<<"��֤��ȷ��:\n";
	cout<<"X��Ӧ��ʮ������x:"<<x<<endl;
	cout<<"X��Ӧ��ʮ������y:"<<y<<endl;
	cout<<"z=x*y\n:";
	z=x*y;				//��z=x*y
	cout<<"�����z:"<<z<<endl;
	return 0;
}
