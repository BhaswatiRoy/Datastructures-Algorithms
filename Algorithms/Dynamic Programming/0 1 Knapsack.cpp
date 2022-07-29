#include<bits/stdc++.h>
using namespace std;

int knapsacksolverecursion(int W,vector<int>&wt,vector<int>&val, int n) 
{ 
    //starting from last index base condition will be when n reaches 0 or no space left in knapsack
    //for smallest valid input as base case we have to return profit as 0
    if(n==0 || W==0)
    {
        return 0;
    }
    if(wt[n-1]<=W)
    {
        //return max value of including and not including the value of current item
        return max((val[n-1]+knapsacksolverecursion(W-wt[n-1],wt,val,n-1)),knapsacksolverecursion(W,wt,val,n-1));
    }
    else if(wt[n-1]>W)
    {
        //if weight of current item is greater than knapsack we can't include that
        return knapsacksolverecursion(W,wt,val,n-1);
    }
}

int knapsackrecursion(int W,vector<int>&wt,vector<int>&val, int n)
{
    int maxprofit=knapsacksolverecursion(W,wt,val,n);
    return maxprofit;
}

//starting from n-1 index we reach up to n index
int knapsacksolvememoization(int W,vector<int>&wt,vector<int>&val, int n,vector<vector<int>>&dp) 
{ 
    //starting from last index base condition will be when n reaches 0 or no space left in knapsack
    //for smallest valid input as base case we have to return profit as 0
    if(n==0 || W==0)
    {
        return dp[n][W]=0;
    }
    //we always check dp vector before doing recursion calls
    if(dp[n][W]!=-1)
    {
        return dp[n][W];
    }
    if(wt[n-1]<=W)
    {
        //return max value of including and not including the value of current item
        //also update the dp vector with that value
        return dp[n][W]=max((val[n-1]+knapsacksolvememoization(W-wt[n-1],wt,val,n-1,dp)),knapsacksolvememoization(W,wt,val,n-1,dp));
    }
    else if(wt[n-1]>W)
    {
        //if weight of current item is greater than knapsack we can't include that
        return dp[n][W]=knapsacksolvememoization(W,wt,val,n-1,dp);
    }
}

int knapsackmemoization(int W,vector<int>&wt,vector<int>&val, int n)
{
    //dp vector stores the n*w value i.e value for any particular weight
    //weight(W) and index(n) are changing variables in recursive solution 
    //so dp vactor has n,W as dimensions
    vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
    int maxprofit=knapsacksolvememoization(W,wt,val,n,dp);
    return maxprofit;
}

int main()
{
    vector<int>val={1,2,3};
    vector<int>wt={4,5,1};
    int n=val.size();
    int W=4;
    
    int ans1=knapsackrecursion(W,wt,val,n);
    cout<<"Max Profit By Recursion:"<<ans1<<endl;
    
    int ans2=knapsackmemoization(W,wt,val,n);
    cout<<"Max Profit By Memoization:"<<ans2<<endl;
}
