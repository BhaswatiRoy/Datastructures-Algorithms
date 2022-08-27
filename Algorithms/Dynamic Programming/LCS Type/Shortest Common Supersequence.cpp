#include<bits/stdc++.h>
using namespace std;

/*
Shortest Common Supersequence - A merged sequence of 2 strings whose subsequences are both initial strings is called supersequence
                                Now the shortest of such merged sequence is shortest common supersequence
*/

//TC=O(2^n), SC=O(1)
int longestcsrecursion(int n, int m, string s1, string s2)
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
        return 1+longestcsrecursion(n-1,m-1,s1,s2);
    }
    else
    {
        //we have 2 choices- x-1 & y, x & y-1 for both strings
        return max(longestcsrecursion(n-1,m,s1,s2),longestcsrecursion(n,m-1,s1,s2));
    }
}

//TC=O(n), SC=O(n^2)
int longestcsmemoization(int n, int m, string s1, string s2,vector<vector<int>>&dp)
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
        return dp[n][m]=1+longestcsmemoization(n-1,m-1,s1,s2,dp);
    }
    else
    {
        //store computed value in dp vector
        return dp[n][m]=max(longestcsmemoization(n-1,m,s1,s2,dp),longestcsmemoization(n,m-1,s1,s2,dp));
    }
}

int main()
{
	//s1+s2 = abcdxycd and lcs(s1,s2)=abxycd(shortest common supersequence)
    string s1="AVnQIELxFb",s2="TEpRbSvi";
    int n=s1.length(),m=s2.length();
    int lcsans1=longestcsrecursion(n,m,s1,s2);
    cout<<"Shortest Common Supersequence By Recursion:"<<(n+m-lcsans1)<<endl;
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    int lcsans2=longestcsmemoization(n,m,s1,s2,dp);
    cout<<"Shortest Common Supersequence By Memoization:"<<(n+m-lcsans2)<<endl;
}

