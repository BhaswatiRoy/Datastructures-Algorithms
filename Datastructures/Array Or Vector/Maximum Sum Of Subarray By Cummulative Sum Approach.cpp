#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() 
{
	vector<int>v={-1,4,7,2};
	int n=v.size();
	//every element initialized with 0
	vector<int>cummulativesum(n+1,0);
	for(int i=1;i<n;i++)
	{
		//cummulative sum at 0th index is considered as 0 so iteration starts from 1
		//storing cummulative sum from 0th to ith index at ith index
		cummulativesum[i]=cummulativesum[i-1]+v[i];
	}
	int maxsum=INT_MIN;
	for(int j=1;j<n;j++)
	{
		int sum=0;
		for(int k=0;k<j;k++)
		{
			//sum between i & j is cummulativesum[j]-cummulativesum[k]
			sum=cummulativesum[j]-cummulativesum[k];
			//update the value of maximum sum
			maxsum=max(sum,maxsum);
		}
	}
	cout<<"Maximum Sum Subarray Is:"<<maxsum<<endl;
}

