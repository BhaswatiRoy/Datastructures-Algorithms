#include<bits/stdc++.h>
using namespace std;

/*
Minimum Insertions To Make String Palindrome - We need to insert some characters in string to make it palindrome
*/

//TC=O(2^n), SC=O(1)
int lpsrecursion(int n, int m, string s1, string s2)
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
        return 1+lpsrecursion(n-1,m-1,s1,s2);
    }
    else
    {
        //we have 2 choices- x-1 & y, x & y-1 for both strings
        return max(lpsrecursion(n-1,m,s1,s2),lpsrecursion(n,m-1,s1,s2));
    }
}

//TC=O(n), SC=O(n^2)
int lpsmemoization(int n, int m, string s1, string s2,vector<vector<int>>&dp)
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
        return dp[n][m]=1+lpsmemoization(n-1,m-1,s1,s2,dp);
    }
    else
    {
        //store computed value in dp vector
        return dp[n][m]=max(lpsmemoization(n-1,m,s1,s2,dp),lpsmemoization(n,m-1,s1,s2,dp));
    }
}

int main()
{
	//a string can be made palindrome if some characters are inserted to match the characters that are not a part of lps
	//thus we need to add characters len(str)-lps
	string str="mbadm";
	string s1=str;
	reverse(str.begin(),str.end());
	string s2=str;
	int n=s1.length(),m=s2.length();
	int ans1=lpsrecursion(n,m,s1,s2);
	cout<<"Minimum Insertions To Make Palindrome By Recursion:"<<(n-ans1)<<endl;
	vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
	int ans2=lpsmemoization(n,m,s1,s2,dp);
	cout<<"Minimum Insertions To Make Palidrome By Memoization:"<<(n-ans2)<<endl;
}

