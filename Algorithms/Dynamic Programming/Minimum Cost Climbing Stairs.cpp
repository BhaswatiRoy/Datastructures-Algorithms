#include<bits/stdc++.h>
using namespace std;

/*
Min Cost Climbing Stairs - In what min cost we can jump from 0th to n-1th stone, it has 2 possible jumps - 1 step, 2 steps
Also at jump from one stair to another costs it energy diff of both stones
This problem is similar to Climbing Stairs (just an extra parameter cost is added)
Also we can solve the opp of this i.e in how many ways we can reach from n-1 to 0 which is same
*/

//recursive approach - TC = O(2^n) (as we are checking 2 possible cases for all cases ) 
int mincostrecursion(int idx,vector<int>&steps)
{
	if(idx==0)
	{
		return 0;
	}
	int left,right;
	//left recursion to jump 1 step
	left=mincostrecursion(idx-1,steps) + abs(steps[idx]-steps[idx-1]);
	//do right recursion only if idx>1 as even if idx=1 then idx-2=-1(invalid step)
	if(idx>1)
	{
		//right recursion to jump 2 steps
		right=mincostrecursion(idx-2,steps)+abs(steps[idx]-steps[idx-2]);
	}
	//since we have to return min steps so min of left & right recursions will be done
	return min(left,right);
}

int mincoststairsrecursion(vector<int>&steps)
{
	int n=steps.size();
	int minsteps=mincostrecursion(n-1,steps);
	return minsteps;
}

//Top Down Approach
//DP with Memoization approach - TC = O(n) (as we are already precomputing some values ) 
int mincostmemoization(int idx,vector<int>&steps,vector<int>&dp)
{
	if(idx==0)
	{
		dp[idx]=0;
		return 0;
	}
	if(dp[idx]!=-1)
	{
		return dp[idx];
	}
	int left,right;
	//left recursion to jump 1 step
	left=mincostmemoization(idx-1,steps,dp) + abs(steps[idx]-steps[idx-1]);
	//do right recursion only if idx>1 as even if idx=1 then idx-2=-1(invalid step)
	if(idx>1)
	{
		//right recursion to jump 2 steps
		right=mincostmemoization(idx-2,steps,dp)+abs(steps[idx]-steps[idx-2]);
	}
	dp[idx]=min(left,right);
	//since we have to return min steps so min of left & right recursions will be done
	return min(left,right);
}

int mincoststairsmemoization(vector<int>&steps)
{
	int n=steps.size();
	vector<int>dp(n+1,-1);
	int minsteps=mincostmemoization(n-1,steps,dp);
	return minsteps;
}

int main()
{
	//vector of costs
	vector<int>steps={30,10,60,10,60,50};
	cout<<"Minimum Cost By Recursion:"<<mincoststairsrecursion(steps)<<endl;
	cout<<"Minimum Cost By Memoization:"<<mincoststairsmemoization(steps)<<endl;
}
