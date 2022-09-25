#include<bits/stdc++.h>
using namespace std;

/*
Longest Increasing Substring - Find the length of the longest substring
*/

int ans1=0,ans2=0;

int lcsrecursion(int n, int m, string s1, string s2)
{
    if(n<0 || m<0)
    {
        return 0;
    }
    int val1=0;
    if(s1[n]==s2[m])
    {
        val1=1+lcsrecursion(n-1,m-1,s1,s2);
    }
    ans1=max(ans1,val1);
    lcsrecursion(n-1,m,s1,s2);
    lcsrecursion(n,m-1,s1,s2);
    return val1;
}

int lcsubstringrecursion(int n, int m, string s1, string s2)
{
    ans1=0;
    lcsrecursion(n-1,m-1,s1,s2);
    return ans1;
}

int lcsmemoization(int n, int m, string s1, string s2, vector<vector<int>>&dp)
{
	if(n<0 || m<0)
    {
        return 0;
    }
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    int val1=0;
    if(s1[n]==s2[m])
    {
        val1=1+lcsmemoization(n-1,m-1,s1,s2,dp);
    }
    ans2=max(ans2,val1);
    lcsmemoization(n-1,m,s1,s2,dp);
    lcsmemoization(n,m-1,s1,s2,dp);
    return dp[n][m]=val1;
}

int lcsubstringmemoization(int n, int m, string s1, string s2)
{
    ans2=0;
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    lcsmemoization(n-1,m-1,s1,s2,dp);
    return ans2;
}

int main()
{
	string s1="ABCDGH", s2="ACDGHR";
	int n=s1.length(),m=s2.length();
	int sz1=lcsubstringrecursion(n,m,s1,s2);
	cout<<"Longest Common Substring By Recursion:"<<sz1<<endl;
	int sz2=lcsubstringmemoization(n,m,s1,s2);
	cout<<"Longest Common Substring By Memoization:"<<sz2<<endl;
}
