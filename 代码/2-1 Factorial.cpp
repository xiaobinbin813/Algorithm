#include<iostream>
using namespace std;
int Factorial(int n)
        {
             if(n==0) return 1;
             return n*Factorial(n-1);   
        }
int main()
{   
    for(int i=0;i<10;i++)
      {
      	  cout<<i<<":  ";
		  cout<<Factorial(i)<<endl;
	  }
    return 0;

}

