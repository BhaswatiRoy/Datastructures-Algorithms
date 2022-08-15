#include<bits/stdc++.h>
using namespace std;

/*
Unbounded Knapsack - We have to find maximum profit we can make from given elements if we can pick the element multiple times
*/

int knapsacksolverecursion(int W,vector<int>&wt,vector<int>&val,int n)
{
	//starting from last index base condition will be when n reaches 0 or no space left in knapsack
    //for smallest valid input as base case we have to return profit as 0
	if(n==0 || W==0)
	{
		return 0;
	}
	if(wt[n-1]<=W)
	{
		//return max value of including and not including the value of current item
		//pick=element not processed - next iteration is again n
		//not pick=element processed - next iteration is n-1
		return max((val[n-1]+knapsacksolverecursion(W-wt[n-1],wt,val,n)),knapsacksolverecursion(W,wt,val,n-1));
	}
	else if(wt[n-1]>W)
	{
		//if weight of current item is greater than knapsack we can't include that
		return knapsacksolverecursion(W,wt,val,n-1);
	}
}

//TC=O(2^n), SC=O(1)
int knapsackrecursion(int W,vector<int>&wt,vector<int>&val,int n)
{
	int maxprofit=knapsacksolverecursion(W,wt,val,n);
	return maxprofit;
}

int knapsacksolvememoization(int W,vector<int>&wt,vector<int>&val,int n,vector<vector<int>>&dp)
{
	if(n==0 || W==0)
	{
		return dp[n][W]=0;
	}
	//we always check dp vector before doing recursion calls
	if(dp[n][W]!=-1)
	{
		return dp[n][W];
	}
	if(wt[n-1]<=W)
	{
		//return max value of including and not including the value of current item and also update the dp vector with that value
		return dp[n][W]=max((val[n-1]+knapsacksolvememoization(W-wt[n-1],wt,val,n,dp)),knapsacksolvememoization(W,wt,val,n-1,dp));
	}
	else if(wt[n-1]>W)
	{
		//if weight of current item is greater than knapsack we can't include that and also update the dp vector with that value
		return dp[n][W]=knapsacksolvememoization(W,wt,val,n-1,dp);
	}
}

int knapsackmemoization(int W,vector<int>&wt,vector<int>&val,int n,vector<vector<int>>&dp)
{
	int maxprofit=knapsacksolvememoization(W,wt,val,n,dp);
	return maxprofit;
}

int main()
{
	int n=4,W=8;
	vector<int>val={1,4,5,7};
	vector<int>wt={1,3,4,5};
	int ans1=knapsackrecursion(W,wt,val,n);
	cout<<"Max Profit By Recursion:"<<ans1<<endl;
	vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
	int ans2=knapsackmemoization(W,wt,val,n,dp);
	cout<<"Max Profit By Memoization"<<ans2<<endl;
}
