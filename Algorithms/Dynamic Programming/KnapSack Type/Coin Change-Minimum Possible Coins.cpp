#include<bits/stdc++.h>
using namespace std;

/*
Coin Change Problem 1 - Find minimum no of coins of different denominations that needs to be taken in combination to represent the total amount of money
                        Similar to unbounded knapsack as we can pick multiple same denomination coins but here instead of "max" we do "min"
*/

//TC=O(2^n), SC=O(1)
int mincoinsrecursion(vector<int>&coins,int amount, int n)
{
	//if there are no elements then mathematically we can pick infinite elements to create given amount
	//if we would have not taken INT_MAX then we would not got minimum on each comparison
	if(n==0)
	{
		//if we used INT_MAX then the +1 in recursion call would have made it INT_MAX+1 which can't be stored in "int" and it would have given -ve value
		return INT_MAX-1;
	}
	//if amount is 0 then we can form that amount by taking no coins which is minimum
	if(amount==0)
	{
		return 0;
	}
	//if coin value is less than or equal to amount then we can either pick it or not pick it
	//previously we used to add knapsack value with pick case now instead of that we are doing +1 for counting
	//because of this +1 we did INT_MAX-1 so that (INT_MAX-1+1) = INT_MAX
	if(coins[n-1]<=amount)
	{
		return min(mincoinsrecursion(coins,amount-coins[n-1],n)+1,mincoinsrecursion(coins,amount,n-1));
	}
	//if coin value is more than the amount then we can not pick it
	else
	{
		return mincoinsrecursion(coins,amount,n-1);
	}
}

//TC=O(n), SC=O(n^2)
int mincoinsmemoization(vector<int>&coins,int amount, int n,vector<vector<int>>&dp)
{
	if(n==0)
	{
		return INT_MAX-1;
	}
	if(amount==0)
	{
		return 0;
	}
	if(dp[n][amount]!=-1)
	{
		return dp[n][amount];
	}
	if(coins[n-1]<=amount)
	{
		return dp[n][amount]=min(mincoinsmemoization(coins,amount-coins[n-1],n,dp)+1,mincoinsmemoization(coins,amount,n-1,dp));
	}
	else
	{
		return dp[n][amount]=mincoinsmemoization(coins,amount,n-1,dp);
	}
}

int main()
{
	vector<int>coins={1,2,5};
	int n=coins.size(),amount=11;
	int ans1=mincoinsrecursion(coins,amount,n);
	cout<<"Minimum Number Of Coins Needed By Recursion:"<<ans1<<endl;
	vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
	int ans2=mincoinsmemoization(coins,amount,n,dp);
	cout<<"Minimum Number Of Coins Needed By Memoization:"<<ans2<<endl;
}
