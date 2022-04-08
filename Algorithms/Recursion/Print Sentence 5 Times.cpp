#include<bits/stdc++.h>
using namespace std;

void name(int count,int base)
{
	if(count==5)
	{
		return;
	}
	cout<<"Hey There!!"<<endl;
	name(count+1,base);
}

int main()
{
	name(0,5);
}

