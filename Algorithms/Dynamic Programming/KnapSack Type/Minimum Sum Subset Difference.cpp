#include<bits/stdc++.h>
using namespace std;

/*
Minimum Sum Subset Difference - Find a partition such that two subsets are created with minimum sum and return the minimum sum finally computed
*/

//TC=O(2^n) SC=O(1)
int findminsumrecursion(vector<int>&nums,int n,int totalsum,int sum)
{
	if(n==0)
	{
		//s1 summation=totalsum-sum, s2 summation=sum
		//we have to return their absolute difference
		return abs((totalsum-sum)-sum);
	}
	//for every element we have 2 choices - pick or not pick
	
	int pick=findminsumrecursion(nums,n-1,totalsum,sum+nums[n-1]);
	int notpick=findminsumrecursion(nums,n-1,totalsum,sum);
	
	//we have to return minimum of both choices
	//as we need to minimize the difference of subsets so returning min sum
	return min(pick,notpick);
}

//TC=O(n) SC=O(n^2)
int findminsummemoization(vector<int>&nums,int n,int totalsum,int sum,vector<vector<int>>&dp)
{
	if(n==0)
	{
		return abs((totalsum-sum)-sum);
	}
	if(dp[n][sum]!=-1)
	{
		return dp[n][sum];
	}
	int pick=findminsummemoization(nums,n-1,totalsum,sum+nums[n-1],dp);
	int notpick=findminsummemoization(nums,n-1,totalsum,sum,dp);
	return dp[n][sum]=min(pick,notpick);
}

int main()
{
	vector<int>nums={1,2,7,9};
	int totalsum=0,n=nums.size();
	for(int i=0;i<n;i++)
	{
		totalsum+=nums[i];
	}
	int minval1=findminsumrecursion(nums,n,totalsum,0);
	cout<<"Min Subset Difference By Recursion:"<<minval1<<endl;
	vector<vector<int>>dp(n+1,vector<int>(totalsum+1,-1));
	int minval2=findminsummemoization(nums,n,totalsum,0,dp);
	cout<<minval2<<endl;
}
