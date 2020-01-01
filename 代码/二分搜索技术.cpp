#include<iostream>
using namespace std;

template<class Type>

int BinarySearch(Type a[ ], const Type &x,int n)
{
	int left=0;
	int right=n-1;
	while(left<=right){
		int middle=(left+right)/2;
		if(x==a[middle])
			return middle;
		else if(x>a[middle])
			left=middle+1;
		else
			right=middle-1;
	}
	return -1;
    
}
int main()
{
	
	int A1[5]={2,4,8,9,10};
	cout<<BinarySearch(A1, 8,4);
	return 0;
}


