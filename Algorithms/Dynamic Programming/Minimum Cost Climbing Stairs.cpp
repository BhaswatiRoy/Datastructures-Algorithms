#include<bits/stdc++.h>
using namespace std;

/*
Min Cost Climbing Stairs - In what min cost we can jump from 0th to nth stair(position after last in vector), it has 2 possible jumps - 1 step, 2 steps
Also standing at any stair i we have to give cost of that stair cost[i] then only we can jump 1 or 2 steps
This problem is modification of Climbing Stairs (just an extra parameter cost is added)
Also we can solve the opp of this i.e in how many ways we can reach from n-1 to 0 which is same
*/

//recursive approach - TC = O(2^n) (as we are checking 2 possible cases for all cases ) 
int mincoststairsrecursion(vector<int>& cost, int idx) 
{
    if (idx<2) 
    {
        return cost[idx];
    }
    int left=mincoststairsrecursion(cost,idx-1);
    int right=mincoststairsrecursion(cost,idx-2);
        
    return cost[idx]+min(left,right);
}

int mincostclimbingstairsrecursion(vector<int>& cost) 
{
    int n=cost.size();
    return min(mincoststairsrecursion(cost,n-1),mincoststairsrecursion(cost,n-2));
}

//Top Down Approach
//DP with Memoization approach - TC = O(n) (as we are already precomputing some values ) 
int mincoststairsmemoization(vector<int>& cost, vector<int>&dp, int idx) 
{
    if (idx<2) 
    {
    	dp[idx]=cost[idx];
        return cost[idx];
    }
    if(dp[idx]!=-1)
    {
    	return dp[idx];
	}
    int left=mincoststairsmemoization(cost,dp,idx-1);
    int right=mincoststairsmemoization(cost,dp,idx-2);
    
    dp[idx]=cost[idx]+min(left,right);
    
    return cost[idx]+min(left,right);
}

int mincostclimbingstairsmemoization(vector<int>& cost) 
{
    int n=cost.size();
	vector<int>dp(n+1,-1);
    return min(mincoststairsmemoization(cost,dp,n-1),mincoststairsmemoization(cost,dp,n-2));
}

int main()
{
	//vector of costs
	vector<int>cost={10,15,20};
	cout<<"Minimum Cost By Recursion:"<<mincostclimbingstairsrecursion(cost)<<endl;
	cout<<"Minimum Cost By Memoization:"<<mincostclimbingstairsmemoization(cost)<<endl;
}
