#include<bits/stdc++.h>
using namespace std;

/*
Longest Repeating Subsequence - The subsequences that occur more than once are called Repeating Subsequence
                                And the longest amongst them is Longest Repeating Subsequence
*/

//TC=O(2^n), SC=O(1)
int lrsrecursion(int n, int m, string s1, string s2)
{
    if(n==0 || m==0)
    {
        return 0;
    }
    //in s1 and s2 we need to find alphabets that are common in both strings with different indices
    if(s1[n-1]==s2[m-1] && n!=m)
    {
        //since last index is common so +1 is done for that index
        //because in recursion calls we are chceking from 2nd last index to beginning
        //also here we got last index same so boh x-1,y-1 called
        return 1+lrsrecursion(n-1,m-1,s1,s2);
    }
    else
    {
        //we have 2 choices- x-1 & y, x & y-1 for both strings
        return max(lrsrecursion(n-1,m,s1,s2),lrsrecursion(n,m-1,s1,s2));
    }
}

//TC=O(n), SC=O(n^2)
int lrsmemoization(int n, int m, string s1, string s2,vector<vector<int>>&dp)
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
	//in s1 and s2 we need to find alphabets that are common in both strings with different indices
    if(s1[n-1]==s2[m-1] && n!=m)
    {
        //store computed value in dp vector
        return dp[n][m]=1+lrsmemoization(n-1,m-1,s1,s2,dp);
    }
    else
    {
        //store computed value in dp vector
        return dp[n][m]=max(lrsmemoization(n-1,m,s1,s2,dp),lrsmemoization(n,m-1,s1,s2,dp));
    }
}

int main()
{
	//a repeating subsequence in string is the lcs of the string and itself with alphabets considered at different indices
	//str="aabcc" -> here lrs="ac" because both occur at different indices twice but b occurs only once so it is not counted
	string str="axxzxy";
	string s1=str,s2=str;
	int n=s1.length(),m=s2.length();
	int ans1=lrsrecursion(n,m,s1,s2);
	cout<<"Longest Repeating Subsequence By Recursion:"<<ans1<<endl;
	vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
	int ans2=lrsmemoization(n,m,s1,s2,dp);
	cout<<"Longest Repeating Subsequence By Memoization:"<<ans2<<endl;
}

