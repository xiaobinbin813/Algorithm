#include<iostream>
using namespace std;
#define Number 3
class Student
{
	private:
		int sno;
		int score;
	public:
		Student(int a,int b)
		{
			sno=a;
			score=b;
			
		}

};
int main()
{
	cout<<sizeof(Student);
	return 0;
}

