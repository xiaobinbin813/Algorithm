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
{//����list[ ]�����д�k��mԪ�ص�ȫ����.
     if (k==m)  
     {//ֻʣ��һ��Ԫ��
            for (int i=0;i<=m;i++)
                  cout<<list[i]<<"  ";
             cout<<endl;
       }
       else//���ж��Ԫ�أ��ݹ��������
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


