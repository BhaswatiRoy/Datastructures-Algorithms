#include<bits/stdc++.h>
using namespace std;

/*
Longest Increasing Subsequence - Find the length of the longest subsequence that is strictly increasing
*/

int lisrecursion(int n,int m,vector<int>&v1,vector<int>&v2)
{
    if(n==0 || m==0)
    {
        return 0;
    }
    if(v1[n-1]==v2[m-1])
    {
        return 1+lisrecursion(n-1,m-1,v1,v2);
    }
    else
    {
        return max(lisrecursion(n-1,m,v1,v2),lisrecursion(n,m-1,v1,v2));
    }
}

int lismemoization(int n,int m,vector<int>&v1,vector<int>&v2,vector<vector<int>>&dp)
{
    if(n==0 || m==0)
    {
        return 0;
    }
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    if(v1[n-1]==v2[m-1])
    {
        return dp[n][m]=1+lismemoization(n-1,m-1,v1,v2,dp);
    }
    else
    {
        return dp[n][m]=max(lismemoization(n-1,m,v1,v2,dp),lismemoization(n,m-1,v1,v2,dp));
    }
}

int main()
{
	vector<int>nums={10,9,2,5,3,7,101,18};
	vector<int>v1=nums;
        set<int>st;
        //since strictly increasing is asked for so we can count length as 1 for consecutive equal elements
        //thus storing them in set is needed to find number of unique elements
        for(int i=0;i<nums.size();i++)
        {
		st.insert(nums[i]);
        }
        vector<int>v2;
        //storing the set elements into another vector which will help us find strictly inrcreasing subsequence
        for(auto it=st.begin();it!=st.end();it++)
        {
                v2.push_back(*it);
        }
        int n=v1.size(),m=v2.size();
        int ans1=lisrecursion(n,m,v1,v2);
        cout<<"Longest Increasing Subsequence By Recursion:"<<ans1<<endl;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans2=lismemoization(n,m,v1,v2,dp);
        cout<<"Longest Increasing Subsequence By Memoization:"<<ans2<<endl;
}

