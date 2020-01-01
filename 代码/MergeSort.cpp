//二路归并排序算法
#include<iostream>
using namespace std;
#define Number 10
template<class Type>
void disp(Type a[],int n)			//输出a中所有元素
{	int i;
	for (i=0;i<n;i++)
		cout<<a[i]<<"  ";
	cout<<endl;

}
template<class Type>

void Merge(Type a[],int low,int mid,int high)
//将a[low..mid]和a[mid+1..high]两个相邻的有序子序列归并为一个有序子序列a[low..high]
{	
	int i=low,j=mid+1,k=0;		//k是tmpa的下标,i、j分别为两个子表的下标
	Type *tmpa=new Type[(high-low+1)*sizeof(Type)];
                               //动态分配空间
	while (i<=mid && j<=high)	//在第1子表和第2子表均未扫描完时循环
		if (a[i]<=a[j])		//将第1子表中的元素放入tmpa中
		{	tmpa[k]=a[i];
			i++;k++; 
		}
		else					//将第2子表中的元素放入tmpa中
		{	tmpa[k]=a[j];
			j++;k++; 
		}
	while (i<=mid)			//将第1子表余下部分复制到tmpa
	{	tmpa[k]=a[i];
		i++;k++; 
	}
	while (j<=high)			//将第2子表余下部分复制到tmpa
	{	tmpa[k]=a[j];
		j++;k++;
	}
	for (k=0,i=low;i<=high;k++,i++) 		//将tmpa复制回a中
		a[i]=tmpa[k];
	delete []tmpa;						//释放tmpa所占内存空间
}

template<class Type>
void MergePass(Type a[],int length,int n)	//一趟二路归并排序
{	int i;
	for (i=0;i+2*length-1<n;i=i+2*length)	//归并length长的两相邻子表
		Merge(a,i,i+length-1,i+2*length-1);
	if (i+length-1<n)					//余下两个子表,后者长度小于length
		Merge(a,i,i+length-1,n-1);		//归并这两个子表
}


template<class Type>
void MergeSort(Type a[],int n)			//二路归并算法
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
