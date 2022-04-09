#include<bits/stdc++.h>
using namespace std;

void func(int i,int n)
{
	if(i<1)
	{
		return;
	}
	func(i-1,n);
	cout<<i<<endl;
}

int main()
{
	func(5,1);
}

