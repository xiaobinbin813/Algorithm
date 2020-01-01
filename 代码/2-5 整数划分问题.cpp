#include<iostream>
using namespace std;
int q(int n,int m)
{
	if((n<1)||(m<1)) return 0;
	else if((n==1)||(m==1)) return 1;
	else if(n<m) return q(n,n);
	else if(n==m) return 1+q(n,n-1);
	else return q(n,m-1)+q(n-m,m);
	
}
int main()
{
	
    cout<<q(6,5);
	return 0;
	
}