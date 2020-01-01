#include<iostream>
using namespace std;

template<class Type>
inline void Swap(Type &a,Type &b)
{
	Type temp=a;
	a=b;
	b=temp;
}
template<class Type>
void Perm(Type list[ ], int k, int m)
{//产生list[ ]数组中从k到m元素的全排列.
     if (k==m)  
     {//只剩下一个元素
            for (int i=0;i<=m;i++)
                  cout<<list[i]<<"  ";
             cout<<endl;
       }
       else//还有多个元素，递归产生排列
            for(int i=k;i<=m;i++)
             {     Swap(list[k],list[i]);
                   Perm(list,k+1,m);
                   Swap(list[k],list[i]);
               }
    
}
int main()
{
	
	int A1[5]={4,9,8,6,2};
	Perm(A1, 0,4);
	return 0;
	
}


