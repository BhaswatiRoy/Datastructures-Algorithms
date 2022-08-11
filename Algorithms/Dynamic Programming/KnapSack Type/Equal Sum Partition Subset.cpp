#include<bits/stdc++.h>
using namespace std;

/*
Equal Sum Partition Subset - Check if a partition is possible such that 2 subsets are formed which have same sum
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

void equalsumpartition(int n,vector<int>&nums)
{
	int totalsum=0;
	for(int i=0;i<n;i++)
	{
		totalsum+=nums[i];
	}
	//if sum is odd then partition is not possible 
	if(totalsum%2!=0)
	{
		cout<<"Can't Partition Subsets"<<endl;
	}
	//if sum is even then partition maybe possible
	else
	{
		//basically we need subsets with sum as totalsum/2 if we need to equally partition
		//like if 22 is sum then we need subsets with sum as 22/2=11
		int s=totalsum/2;
		//so we will apply subset sum logic with totalsum/2 as sum value
		bool ans1=subsetsumsolverecursion(s,nums,n);
		if(ans1==true)
		{
			cout<<"Can Partition Subsets By Recursion"<<endl;
		}
		else
		{
			cout<<"Can Not Partition Subsets By Recursion"<<endl;
		}
		vector<vector<int>>dp(n+1,vector<int>(s+1,-1));
		bool ans2=subsetsumsolvememoization(s,nums,n,dp);
		if(ans2==true)
		{
			cout<<"Can Partition Subsets By Memoization"<<endl;
		}
		else
		{
			cout<<"Can Not Partition Subsets By Memoization"<<endl;
		}
	}
}

int main()
{
	vector<int>nums={1,5,11,5};
	int n=nums.size();
	equalsumpartition(n,nums);
}
