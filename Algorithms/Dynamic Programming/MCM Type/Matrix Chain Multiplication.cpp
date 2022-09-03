#include<bits/stdc++.h>
using namespace std;

/*
Matrix Chain Multiplication - Given a series of matrix dimensions we need to find the minimum cost to multiply the matrices
*/

int mcmrecursion(vector<int>&arr, int i, int j)
{
    if(i>=j)
    {
        return 0;
    }
    int minans=INT_MAX;
    //k is the partition point in array which partitions into 2 parts 
    // 1st - i to k, 2nd part - k+1 to j
    //k also iterated from i to j everytime recursively changing partition point
    for(int k=i;k<j;k++)
    {
        //temporary ans is (left call from i to k) + (right call from k+1 to j) + cost of operation
        int tempans=mcmrecursion(arr,i,k)+mcmrecursion(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        //update minimum value everytime needed
        minans=min(tempans,minans);
    }
    return minans;
}

int mcmmemoization(vector<int>&arr, int i, int j, vector<vector<int>>&dp)
{
	if(i>=j)
	{
		return 0;
	}
	if(dp[i][j]!=-1)
        {
                return dp[i][j];
        }
	int minans=INT_MAX;
        for(int k=i;k<j;k++)
        {
    	        int tempans=mcmmemoization(arr,i,k,dp)+mcmmemoization(arr,k+1,j,dp)+(arr[i-1]*arr[k]*arr[j]);
    	        minans=min(tempans,minans);
	}
	return minans;
}

int main()
{
	//if size/arr vector is 5 then there are 4 matrices
	//A0 = 40 x 20, A1 = 20 x 30, A2 = 30 x 10, A3 = 10 x 30
	//and i will start from i so that while calculating cost we need A[i-1] and we don't get error in that
	vector<int>arr={40,20,30,10,30};
	int n=arr.size();
	int i=1,j=n-1;
	int ans1=mcmrecursion(arr,i,j);
	cout<<"Minimum Cost Of Matrix Chain Multiplication By Recursion:"<<ans1<<endl;
	//dp vector will be of size dimensions i,j and maximum value of both i and j is n
	vector<vector<int>>dp(n,vector<int>(n,-1));
	int ans2=mcmmemoization(arr,i,j,dp);
	cout<<"Minimum Cost Of Matrix Chain Multiplication By Memoization:"<<ans2<<endl;
}

