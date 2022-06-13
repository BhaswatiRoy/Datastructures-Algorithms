#include<bits/stdc++.h>
using namespace std;

/*
Clibing Stairs - In how many ways we can reach to n from 1
This problem is similar to Fibonacci Series Question
Also we can solve the opp of this i.e in how many ways we can reach from n to 1 which is same
*/

//recursive approach - TC = O(2^n) (as we are checking 2 possible cases for all cases ) 
int countwaysrecursion(int idx)
{
    //we are starting from nth stair and coming to 1st stair which is same as opposite way
    //straight away jump from 1st to nth stair
    //suppose idx=1 then in next recursion calls we get idx-1=0 & idx-2=-1 but we don't need cond for those as 1 is base case
    if(idx==1 || idx==2)
    {
        return idx;
    }
    //check for all possible ways here by both 1 & 2 steps
    int left=countwaysrecursion(idx-1);
    int right=countwaysrecursion(idx-2);
        
    //in end return sum of all possible ways
    return left+right;
}
int climbstairsrecursion(int n) 
{
    int count=countwaysrecursion(n);
    return count;
}

//DP with Memoization approach - TC = O(n) (as we are already precomputing some values ) 
int countwaysmemoization(int idx,vector<int>&dp)
{
    //compute the value of base case and store it in dp vector
    if(idx==1 || idx==2)
    {
        dp[idx]=idx;
        return idx;
    }
    //check if the current case exists in dp vector then use that and don't compute again
    if(dp[idx]!=-1)
    {
        return dp[idx];
    }
    int left=countwaysmemoization(idx-1,dp);
    int right=countwaysmemoization(idx-2,dp);
    //compute the value of other cases and store it in dp vector
    dp[idx]=left+right;
           
    return left+right;
}
int climbstairsmemoization(int n) 
{
    vector<int>dp(46,-1);
    int count=countwaysmemoization(n,dp);
    return count;
}

int main()
{
	int n=5;
	cout<<"Number Of Steps By Recursion "<<climbstairsrecursion(n)<<endl;
	cout<<"Number Of Steps By Memoization "<<climbstairsmemoization(n)<<endl;
}
