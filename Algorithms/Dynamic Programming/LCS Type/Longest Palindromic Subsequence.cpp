#include<bits/stdc++.h>
using namespace std;

/*
Longest Palindromic Subsequence - A subsequence in the String which is palindrome is called Palindromic Subsequence
                                  And the longest one of those is LPS
*/

//TC=O(2^n), SC=O(1)
int lcsrecursion(int n, int m, string s1, string s2)
{
    if(n==0 || m==0)
    {
        return 0;
    }
    if(s1[n-1]==s2[m-1])
    {
        //since last index is common so +1 is done for that index
        //because in recursion calls we are chceking from 2nd last index to beginning
        //also here we got last index same so boh x-1,y-1 called
        return 1+lcsrecursion(n-1,m-1,s1,s2);
    }
    else
    {
        //we have 2 choices- x-1 & y, x & y-1 for both strings
        return max(lcsrecursion(n-1,m,s1,s2),lcsrecursion(n,m-1,s1,s2));
    }
}

//TC=O(n), SC=O(n^2)
int lcsmemoization(int n, int m, string s1, string s2,vector<vector<int>>&dp)
{
    if(n==0 || m==0)
    {
        return 0;
    }
    //check if value is present in dp vector
    if(dp[n][m]!=-1)
    {
    	return dp[n][m];
	}
    if(s1[n-1]==s2[m-1])
    {
        //store computed value in dp vector
        return dp[n][m]=1+lcsmemoization(n-1,m-1,s1,s2,dp);
    }
    else
    {
        //store computed value in dp vector
        return dp[n][m]=max(lcsmemoization(n-1,m,s1,s2,dp),lcsmemoization(n,m-1,s1,s2,dp));
    }
}

int main()
{
	//having s1=s and s2=reverse(s) if we try to find lcs between them then it is lps
	//because palindromic subsequence remains same even after reversal
	string s="bbabcbcab";
	string s1=s;
	reverse(s.begin(),s.end());
	string s2=s;
	int n=s1.length(),m=s2.length();
	int ans1=lcsrecursion(n,m,s1,s2);
	cout<<"Longest Palindromic Subsequence By Recursion:"<<ans1<<endl;
	vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
	int ans2=lcsmemoization(n,m,s1,s2,dp);
	cout<<"Longest Palindromic Subsequence By Memoization:"<<ans2<<endl;
}

