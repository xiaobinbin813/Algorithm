#include<iostream>
using namespace std;
int fibonacci(int n)
   {
       if (n <= 1) return 1;
       return fibonacci(n-1)+fibonacci(n-2);
   }

int main()
{   
    for(int i=0;i<10;i++)
      {
      	  cout<<i<<":  ";
		  cout<<fibonacci(i)<<endl;
	  }
    return 0;

}

