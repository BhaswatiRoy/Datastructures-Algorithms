#include<bits/stdc++.h>
using namespace std;

/* Parameterized Recursion */

void summation(int sum,int i,int n)
{
	//as soon as base case is hit we have sum ready for printing
	if(i>n)
	{
		cout<<sum<<endl;
		return;
	}
	//else continue adding into sum
	sum+=i;
	//recursive call and i+1 is taken as we keep considering next numbers
	summation(sum,i+1,n);
}

int main()
{
	summation(0,1,5);
}

