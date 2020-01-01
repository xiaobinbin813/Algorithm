//��·�鲢�����㷨
#include<iostream>
using namespace std;
#define Number 6
class Student
{
	private:
		int sno;
		int score;
		
	public:

		Student(int a=0,int b=0)
		{
			sno=a;
			score=b;
		}
		friend void disp(Student a[],int n);
		bool operator <=(Student b)
		{
			return score<=b.score;
		}
};

void disp(Student a[],int n)			//���a������Ԫ��
{	int i;
	for (i=0;i<n;i++)
		cout<<a[i].score<<"  ";
	cout<<endl;

}

void Merge(Student a[],int low,int mid,int high)
//��a[low..mid]��a[mid+1..high]�������ڵ����������й鲢Ϊһ������������a[low..high]
{	
	
	int i=low,j=mid+1,k=0;		//k��tmpa���±�,i��j�ֱ�Ϊ�����ӱ���±�

	Student *tmpa=new Student[(high-low+1)*sizeof(Student)];                   //��̬����ռ�
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
	//disp(tmpa,Number);
	delete []tmpa;						//�ͷ�tmpa��ռ�ڴ�ռ�
}


void MergePass(Student a[],int length,int n)	//һ�˶�·�鲢����
{	int i;
	for (i=0;i+2*length-1<n;i=i+2*length)	//�鲢length�����������ӱ�
		Merge(a,i,i+length-1,i+2*length-1);
	if (i+length-1<n)					//���������ӱ�,���߳���С��length
		Merge(a,i,i+length-1,n-1);		//�鲢�������ӱ�
}



void MergeSort(Student a[],int n)			//��·�鲢�㷨
{	int length;
	for (length=1;length<n;length=2*length)
		MergePass(a,length,n);
}
int  main()
{
    Student a[Number]={Student(12,100),Student(10,200),Student(8,300),Student(22,1100),Student(11,600),Student(18,400)};

    
	cout<<" before sorted:";
	disp(a,Number);
	MergeSort(a,Number);
	cout<<"after sorted:";
	disp(a,Number);
	return 0;
}
