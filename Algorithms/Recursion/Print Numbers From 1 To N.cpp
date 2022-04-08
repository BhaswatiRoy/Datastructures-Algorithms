#include<bits/stdc++.h>
using namespace std;

void name(int i,int n)
{
	if(i>n)
	{
		return;
	}
	cout<<i<<endl;
	name(i+1,n);
}

int main()
{
	name(1,5);
}

