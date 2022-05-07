#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n,vector<int>&dp)
{
	if(n<=1)
	{
		return n;
	}
	if(dp[n]!=-1)
	{
		return dp[n];
	}
	return dp[n]=fibonacci(n-1,dp)+fibonacci(n-2,dp);
}

int main()
{
	int n;
	cout<<"Enter The Value Of n:";
	cin>>n;
	vector<int>dp(n+1,-1);
	fibonacci(n,dp);
	int ans=fibonacci(n,dp);
	cout<<"The Value Of nth Factorial is:"<<ans;
}
