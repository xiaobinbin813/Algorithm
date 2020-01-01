#include<iostream>
using namespace std;
static int count=0;
void move(int s,int t)
{
	cout<<s<<"-->"<<t<<endl;
	count++;
}
void hanoi(int n,int a,int b,int c)
{
	if(n>0)
		{
		hanoi(n-1,a,c,b);
		move(a,b);
		hanoi(n-1,c,b,a);
		}
		
	
}
int main()
{
	
    hanoi(5,1,2,3);
    cout<<count<<endl;;
    return 0;
	
}


