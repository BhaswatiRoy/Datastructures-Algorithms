#include<bits/stdc++.h>
using namespace std;

/*
Target Sum - Assign +/- signs to each numbers such that their total sum is given sum and we have to return count of such arrays
*/

//TC=O(2^n), SC=O(1)
int targetsumrecursion(int sum,vector<int>&nums,int n)
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
		return targetsumrecursion(sum-nums[n-1],nums,n-1)+targetsumrecursion(sum,nums,n-1);
	}
	//if the current value is more than sum then we have only one option of not picking it
	else if(nums[n-1]>sum)
	{
		return targetsumrecursion(sum,nums,n-1);
	}
}

//TC=O(n), SC=O(n^2)
int targetsummemoization(int sum,vector<int>&nums,int n,vector<vector<int>>&dp)
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
		return dp[n][sum]=targetsummemoization(sum-nums[n-1],nums,n-1,dp)+targetsummemoization(sum,nums,n-1,dp);
	}
	//return computed value and simultaneously store in dp vector
	else if(nums[n-1]>sum)
	{
		return dp[n][sum]=targetsummemoization(sum,nums,n-1,dp);
	}
}

int main()
{
	vector<int>nums={1,1,2,3};
	int totalsum=0,n=nums.size(),reqsum=1;
	for(int i=0;i<nums.size();i++)
	{
		totalsum+=nums[i];
	}
	//+1-1-2+3 = 1
	//dividing the array as - 3+1 & -1-2 = (3+1) - (1+2) = reqsum(diff)
	//thus basically we are finding difference of both subsets and returning count of those
	//thus we need subsets with sum=(reqsum+totalsum)/2
	int sum=(reqsum+totalsum)/2;
	int ans1=targetsumrecursion(sum,nums,n);
	cout<<"Count Of Target Sum Subsets By Recursion:"<<ans1<<endl;
	vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
	int ans2=targetsummemoization(sum,nums,n,dp);
	cout<<"Count Of Target Sum Subsets By Memoization:"<<ans2<<endl;
}
