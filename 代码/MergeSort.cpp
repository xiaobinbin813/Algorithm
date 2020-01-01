//��·�鲢�����㷨
#include<iostream>
using namespace std;
#define Number 10
template<class Type>
void disp(Type a[],int n)			//���a������Ԫ��
{	int i;
	for (i=0;i<n;i++)
		cout<<a[i]<<"  ";
	cout<<endl;

}
template<class Type>

void Merge(Type a[],int low,int mid,int high)
//��a[low..mid]��a[mid+1..high]�������ڵ����������й鲢Ϊһ������������a[low..high]
{	
	int i=low,j=mid+1,k=0;		//k��tmpa���±�,i��j�ֱ�Ϊ�����ӱ���±�
	Type *tmpa=new Type[(high-low+1)*sizeof(Type)];
                               //��̬����ռ�
	while (i<=mid && j<=high)	//�ڵ�1�ӱ�͵�2�ӱ��δɨ����ʱѭ��
		if (a[i]<=a[j])		//����1�ӱ��е�Ԫ�ط���tmpa��
		{	tmpa[k]=a[i];
			i++;k++; 
		}
		else					//����2�ӱ��е�Ԫ�ط���tmpa��
		{	tmpa[k]=a[j];
			j++;k++; 
		}
	while (i<=mid)			//����1�ӱ����²��ָ��Ƶ�tmpa
	{	tmpa[k]=a[i];
		i++;k++; 
	}
	while (j<=high)			//����2�ӱ����²��ָ��Ƶ�tmpa
	{	tmpa[k]=a[j];
		j++;k++;
	}
	for (k=0,i=low;i<=high;k++,i++) 		//��tmpa���ƻ�a��
		a[i]=tmpa[k];
	delete []tmpa;						//�ͷ�tmpa��ռ�ڴ�ռ�
}

template<class Type>
void MergePass(Type a[],int length,int n)	//һ�˶�·�鲢����
{	int i;
	for (i=0;i+2*length-1<n;i=i+2*length)	//�鲢length�����������ӱ�
		Merge(a,i,i+length-1,i+2*length-1);
	if (i+length-1<n)					//���������ӱ�,���߳���С��length
		Merge(a,i,i+length-1,n-1);		//�鲢�������ӱ�
}


template<class Type>
void MergeSort(Type a[],int n)			//��·�鲢�㷨
{	int length;
	for (length=1;length<n;length=2*length)
		MergePass(a,length,n);
}
int  main()
{
    float a[Number]={2.5,5.5,1,7.9,10,6,9,4,3,8};
	cout<<" before sorted:";
	disp(a,Number);
	MergeSort(a,Number);
	cout<<"after sorted:";
	disp(a,Number);
	return 0;
}
