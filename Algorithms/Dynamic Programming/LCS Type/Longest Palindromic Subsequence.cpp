#include<bits/stdc++.h>
using namespace std;

/*
Longest Palindromic Subsequence - A subsequence in the String which is palindrome is called Palindromic Subsequence
                                  And the longest one of those is LPS
*/

//TC=O(2^n), SC=O(1)
int lpsrecursion(int n, int m, string s1, string s2)
{
    if(n==0 || m==0)
    {
        return 0;
    }
    //checking from last if characters from both strings have same value
    //then reduce length of both strings in next recursion call
    //1+ is done for counting this index value being same
    if(s1[n-1]==s2[m-1])
    {
        return 1+lpsrecursion(n-1,m-1,s1,s2);
    }
    //if not same then reduce length of each one by one in next recursion calls
    //then return the max length obtained
    return max(lpsrecursion(n-1,m,s1,s2),lpsrecursion(n,m-1,s1,s2));
}

//TC=O(n), SC=O(n^2)
int lpsmemoization(int n, int m, string s1, string s2, vector<vector<int>>&dp)
{
    if(n==0 || m==0)
    {
        return 0;
    }
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    //checking from last if characters from both strings have same value
    //then reduce length of both strings in next recursion call
    //1+ is done for counting this index value being same
    if(s1[n-1]==s2[m-1])
    {
        return dp[n][m]=1+lpsmemoization(n-1,m-1,s1,s2);
    }
    //if not same then reduce length of each one by one in next recursion calls
    //then return the max length obtained
    return dp[n][m]=max(lpsmemoization(n-1,m,s1,s2),lpsmemoization(n,m-1,s1,s2));
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

