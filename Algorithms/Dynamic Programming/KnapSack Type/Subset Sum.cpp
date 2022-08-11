#include<bits/stdc++.h>
using namespace std;

/*
Subset Sum - Check if there is any subset present with sum equal to target sum
*/

//TC=O(2^n), SC=O(1)
bool subsetsumsolverecursion(int sum,vector<int>&nums,int n)
{
	//if sum is 0 then we can get that sum by picking no elements in subset
	if(sum==0)
	{
		return true;
	}
	//if there are no elements in subset we can't form the given sum
	if(n==0)
	{
		return false;
	}
	//if the current value is less than sum then we can either pick it or not pick it
	//in any of the cases if we get T then we will return T
	if(nums[n-1]<=sum)
	{
		return subsetsumsolverecursion(sum-nums[n-1],nums,n-1) || subsetsumsolverecursion(sum,nums,n-1);	
	}
	//if the current value is more than sum then we have only one option of not picking it
	else if(nums[n-1]>sum)
	{
		return subsetsumsolverecursion(sum,nums,n-1);
	}
}

//TC=O(n), SC=O(1)
bool subsetsumsolvememoization(int sum,vector<int>&nums,int n,vector<vector<int>>&dp)
{
	if(sum==0)
	{
		return true;
	}
	if(n==0)
	{
		return false;
	}
	//if the subset sum boolean value is present in dp vector then we will return that only
	if(dp[n][sum]!=-1)
	{
		return dp[n][sum];
	}
	//return computed value and simultaneously store in dp vector
	if(nums[n-1]<=sum)
	{
		return dp[n][sum]=subsetsumsolvememoization(sum-nums[n-1],nums,n-1,dp) || subsetsumsolvememoization(sum,nums,n-1,dp);
	}
	//return computed value and simultaneously store in dp vector
	else if(nums[n-1]>sum)
	{
		return dp[n][sum]=subsetsumsolvememoization(sum,nums,n-1,dp);
	}
}

int main()
{
	vector<int>nums={2,3,7,8};
	int sum=11,n=nums.size();
	bool ans1=subsetsumsolverecursion(sum,nums,n);
	cout<<ans1<<endl;
	vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
	bool ans2=subsetsumsolvememoization(sum,nums,n,dp);
	cout<<ans2<<endl;
}
