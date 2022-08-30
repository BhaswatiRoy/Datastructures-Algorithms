#include<bits/stdc++.h>
using namespace std;

/*
Is Subsequence/Sequence Pattern Matching - We have to find if one string is subsequence of another
*/

//TC=O(2^n), SC=O(1)
int lcsrecursion(int n, int m, string s1, string s2)
{
    if(n==0 || m==0)
    {
        return 0;
    }
    //in s1 and s2 we need to find alphabets that are common in both strings with different indices
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
	//in s1 and s2 we need to find alphabets that are common in both strings with different indices
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

//TC=O(n), SC=O(1)
bool subsequencetwopointers(int n, int m, string s1, string s2)
{
	int i=0;
	//traverse both strings with two pointers
    //compare current char of s with unmatched chars of t
	for(int j=0;i<n,j<m;j++)
	{
		//if a match is found then increment the iterator of s
		if(s1[i]==s2[j])
		{
			i++;
		}
	}
	//in end if all chars of string s is matched then we will return true
	if(i==n)
	{
		return true;
	}
	return false;
}

int main()
{
	//if s1 is subsequence of s2 then s1 must be the lcs of s1 & s2
	//length of lcs varies from 0(no lcs) to min(length(s1),length(s2))
	//thus if we get any length then that must be of lcs so length is enough here to decide
	string s1="abc",s2="ahbgdc";
	int n=s1.length(),m=s2.length();
	int ans1=lcsrecursion(n,m,s1,s2);
	if(ans1==s1.length())
	{
		cout<<"String 1 Is Subsequence Of String 2 By Recursion"<<endl;
	}
	else
	{
		cout<<"String 1 Is Not Subsequence Of String 2 By Recursion"<<endl;
	}
	vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
	int ans2=lcsmemoization(n,m,s1,s2,dp);
	if(ans2==s1.length())
	{
		cout<<"String 1 Is Subsequence Of String 2 By Memoization"<<endl;
	}
	else
	{
		cout<<"String 1 Is Not Subsequence Of String 2 By Memoization"<<endl;
	}
	bool ans3=subsequencetwopointers(n,m,s1,s2);
	if(ans3==true)
	{
		cout<<"String 1 Is Subsequence Of String 2 By Two Pointers"<<endl;
	}
	else
	{
		cout<<"String 1 Is Not Subsequence Of String 2 By Two Pointers"<<endl;
	}
}

