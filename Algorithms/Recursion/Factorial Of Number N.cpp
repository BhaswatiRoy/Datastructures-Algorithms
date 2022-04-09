#include<bits/stdc++.h>
using namespace std;

int fact(int n)
{
	//if base case condition is hit then return 0
	if(n==0)
	{
		return 1;
	}
	//else keep waiting till all recursion calls are over
	//fact(x)->gives product of all numbers from 1 to x
	return n*fact(n-1);
}

int main()
{
	int val=fact(5);
	cout<<val<<endl;
}

