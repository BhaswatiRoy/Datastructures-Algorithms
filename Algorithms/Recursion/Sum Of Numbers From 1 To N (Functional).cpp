#include<bits/stdc++.h>
using namespace std;

/* Functional Recursion */

int summation(int n)
{
	//if base case condition is hit then return 0
	if(n==0)
	{
		return 0;
	}
	//else keep waiting till all recursion calls are over
	//summation(x)->gives summation of all numbers from 1 to x
	return n+summation(n-1);
}

int main()
{
	int val=summation(5);
	cout<<val<<endl;
}

