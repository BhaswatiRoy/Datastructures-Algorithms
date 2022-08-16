#include<bits/stdc++.h>
using namespace std;

/*
Rod Cutting Problem - We have to cut a rod of length n into as many pieces as possible and given the price corresponding to length of pieces we need to find the maximum possible profit
                      This is a variation of Rod Cutting Problem
*/

//TC=O(2^n) SC=O(1)
int rodcutsolverecursion(vector<int>&price,vector<int>&length,int n,int N)
{
	//starting from last index base condition will be when n reaches 0 or no rod length left to be taken
    //for smallest valid input as base case we have to return price as 0
	if(n==0 || N==0)
	{
		return 0;
	}
	if(length[n-1]<=N)
	{
		//return max value of including and not including the value of current item
		//pick=element not processed - next iteration is again n
		//not pick=element processed - next iteration is n-1
		return max((price[n-1]+rodcutsolverecursion(price,length,n,N-length[n-1])),rodcutsolverecursion(price,length,n-1,N));
	}
	else if(length[n-1]<=N)
	{
		//if weight of current item is greater than knapsack we can't include that
		return rodcutsolverecursion(price,length,n-1,N);
	}
}

//TC=O(n) SC=O(n^2)
int rodcutmemoization(vector<int>&price,vector<int>&length,int n,int N,vector<vector<int>>&dp)
{
	if(n==0 || N==0)
	{
		return dp[n][N]=0;
	}
	//we always check dp vector before doing recursion calls
	if(dp[n][N]!=-1)
    {
        return dp[n][N];
    }
    if(length[n-1]<=N)
	{
		//return max value of including and not including the value of current item and also update the dp vector with that value
		return dp[n][N]=max((price[n-1]+rodcutmemoization(price,length,n,N-length[n-1],dp)),rodcutmemoization(price,length,n-1,N,dp));
	}
	else if(length[n-1]<=N)
	{
		//if weight of current item is greater than knapsack we can't include that and also update the dp vector with that value
		return dp[n][N]=rodcutmemoization(price,length,n-1,N,dp);
	}
}

int main()
{
	//n=length of rod & price vector, N=same as n but also acts as W in knapsack
	int n=8,N=8;
	//price vector acts as profit vector in knapsack
	vector<int>price={3, 5, 8, 9, 10, 17, 17, 20};
	//length vector acts as weight vector in knapsack
	vector<int>length;
	for(int i=1;i<=n;i++)
	{
		length.push_back(i);
	}
	int ans1=rodcutsolverecursion(price,length,n,N);
	cout<<ans1<<endl;
	vector<vector<int>>dp(n+1,vector<int>(N+1,-1));
	int ans2=rodcutmemoization(price,length,n,N,dp);
	cout<<ans2<<endl;
}
