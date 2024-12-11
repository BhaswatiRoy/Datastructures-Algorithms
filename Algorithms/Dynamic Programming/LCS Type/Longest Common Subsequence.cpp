#include<bits/stdc++.h>
using namespace std;

/*
Longest Common Subsequence - Find the longest subsequence that is common in both strings
*/

//TC=O(2^n), SC=O(1)
int longestlcsrecursion(int n, int m, string s1, string s2)
{
    //s1 = "abc", s2 = "", common ="" so 0 length common subsequence
    if(n==0 || m==0)
    {
        return 0;
    }
    //checking from last if characters from both strings have same value
    //then reduce length of both strings in next recursion call
    //1+ is done for counting this index value being same
    if(s1[n-1]==s2[m-1])
    {
        return 1+longestlcsrecursion(n-1,m-1,s1,s2);
    }
    //if not same then reduce length of each one by one in next recursion calls
    //then return the max length obtained
    return max(longestlcsrecursion(n-1,m,s1,s2),longestlcsrecursion(n,m-1,s1,s2));
}

//TC=O(n), SC=O(n^2)
int longestlcsmemoization(int n, int m, string s1, string s2, vector<vector<int>>&dp)
{
    //s1 = "abc", s2 = "", common ="" so 0 length common subsequence
    if(n==0 || m==0)
    {
        return 0;
    }
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    //checking from last if characters from both strings have the same value
    //then reduce the length of both strings in the next recursion call
    //1+ is done for counting this index value being the same
    if(s1[n-1]==s2[m-1])
    {
        return dp[n][m]=1+longestlcsmemoization(n-1,m-1,s1,s2);
    }
    //if not same then reduce length of each one by one in next recursion calls
    //then return the max length obtained
    return dp[n][m]=max(longestlcsmemoization(n-1,m,s1,s2),longestlcsmemoization(n,m-1,s1,s2));
}

int main()
{
	string s1="ABCDGH",s2="AEDFHR";
	int n=s1.length(),m=s2.length();
        int ans1=longestlcsrecursion(n,m,s1,s2);
        cout<<ans1<<endl;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans2=longestlcsmemoization(n,m,s1,s2,dp);
        cout<<ans2<<endl;
}
