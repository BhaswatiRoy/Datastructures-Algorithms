#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Kadane's Algorithm= states that we get max sum of subarray at a point where we have max contiguos +ve integers
As soon as we get -ve sum that will not be counted so we will store the sum and set sum=0
*/

int main()
{
	//Kadane's Algorithm->{0(-1) , 4 , 0(-2) , 7 , 3}
	vector<int>v={-1,4,-6,7,-4};
	int currsum=0, maxsum=INT_MIN;
	for(int i=0;i<v.size();i++)
	{
		currsum+=v[i];
		if(currsum>maxsum)
		{
			maxsum=currsum;
		}
		//this will work even if all numbers in vector is -ve
		//if we assign currsum=0 then we will get 0 for vectors which have all values as -ve
		if(currsum<0)
		{
			currsum=0;
		}
	}
	cout<<maxsum;
}
