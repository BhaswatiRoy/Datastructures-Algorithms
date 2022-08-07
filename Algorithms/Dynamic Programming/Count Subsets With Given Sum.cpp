#include<bits/stdc++.h>
using namespace std;

/*
Count Subsets With Given Sum - Count the total number of subsets with a given sum
*/

//TC=O(2^n), SC=O(1)
int countsubsetsumrecursion(int sum,vector<int>&nums,int n)
{
	//if sum is 0 then we can get that sum by picking no elements in subset
	//so count this subset as 1 subset
	if(sum==0)
	{
		return 1;
	}
	//if there are no elements in subset we can't form the given sum
	//so can't count this subset
	if(n==0)
	{
		return 0;
	}
	//if the current value is less than sum then we can either pick it or not pick it
	//we will take sum of counts of subsets from both recursive calls
	if(nums[n-1]<=sum)
	{
		return countsubsetsumrecursion(sum-nums[n-1],nums,n-1)+countsubsetsumrecursion(sum,nums,n-1);
	}
	//if the current value is more than sum then we have only one option of not picking it
	else if(nums[n-1]>sum)
	{
		return countsubsetsumrecursion(sum,nums,n-1);
	}
}

//TC=O(n), SC=O(1)
int countsubsetsummemoization(int sum,vector<int>&nums,int n,vector<vector<int>>&dp)
{
	if(sum==0)
	{
		return 1;
	}
	if(n==0)
	{
		return 0;
	}
	//if count of subsets is present in dp vector then we will return that only
	if(dp[n][sum]!=-1)
	{
		return dp[n][sum];
	}
	//return computed value and simultaneously store in dp vector
	if(nums[n-1]<=sum)
	{
		return dp[n][sum]=countsubsetsummemoization(sum-nums[n-1],nums,n-1,dp)+countsubsetsummemoization(sum,nums,n-1,dp);
	}
	//return computed value and simultaneously store in dp vector
	else if(nums[n-1]>sum)
	{
		return dp[n][sum]=countsubsetsummemoization(sum,nums,n-1,dp);
	}
}

int main()
{
	vector<int>nums={2,3,5,6,8,10};
	int sum=10,n=nums.size();
	int ans1=countsubsetsumrecursion(sum,nums,n);
	cout<<"No Of Subsets With Given Sum By Recursion:"<<ans1<<endl;
	vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
	int ans2=countsubsetsummemoization(sum,nums,n,dp);
	cout<<"No Of Subsets With Given Sum By Memoization:"<<ans2<<endl;
}
