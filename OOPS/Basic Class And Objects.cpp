#include<bits/stdc++.h>
using namespace std;

//class declared
class employee
{
	//important variables - private access specifier
	private:
		int a,b;
	//no so important variables - public access specifier
	public:
		int c;
		void setdata(int a1, int b1)
		{
			a=a1;
			b=b1;
		}
		void getdata()
		{
			cout<<"Value Of a:"<<a<<endl;
			cout<<"Value Of b:"<<b<<endl;
			cout<<"Value of c:"<<c<<endl;
		}
};

int main()
{
	employee e;
	e.c=7;
	e.setdata(2,5);
	e.getdata();
}
