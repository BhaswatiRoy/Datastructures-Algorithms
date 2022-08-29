#include<bits/stdc++.h>
using namespace std;

/*
Minimum Number Of Deletions To Make String Palindrome - We need to delete some characters from given string to make it palindrome
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
	//a string can be palindrome if it is converted to it's longest palindrome subsequence
	//so we need to delete all characters that are not a part of lps
	string str="aebcbda";
	string s1=str;
	reverse(str.begin(),str.end());
	string s2=str;
	int n=s1.length(),m=s2.length();
	int lpsans1=lcsrecursion(n,m,s1,s2);
	cout<<"Minimum Deletions To Make Palindrome By Recursion:"<<abs(str.length()-lpsans1)<<endl;
	int lpsans2=lcsmemoization(n,m,s1,s2);
	cout<<"Minimum Deletions To Make Palindrome By Memoization"<<abs(str.length()-lpsans2)<<endl;
}

