#include<bits/stdc++.h>
using namespace std;

/*
Palindrome Partition 2 - Count Minimum Number Of Partitions To Make All Resulting Partition String Palindrome
*/

bool ispalindrome(int i, int j, string&s)
{
    while(i<j)
    {
        if(s[i]!=s[j]) 
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int palpartitionrecursion(int i, int j, string s)
{
	if(i>=j)
	{
		return 0;
	}
	if(ispalindrome(i,j,s)==true)
	{
		return 0;
	}
	int minans=INT_MAX;
	for(int k=i;k<j;k++)
	{
		if(ispalindrome(i,k,s)==false)
		{
			continue;
		}
		//temporary ans is (left call from i to k) + (right call from k+1 to j) + cost of operation
        //here cost of operation is 1 because we did 1 partition to check further
        int tempans= palpartitionrecursion(i,k,s) + palpartitionrecursion(k+1,j,s) + 1;
        minans=min(minans,tempans);
	}
	return minans;
}

int palpartitionmemoization(int i, int j, string s, vector<vector<int>>&dp)
{
	if(i>=j)
    {
        return dp[i][j]=0;
    }
    if(ispalindrome(i,j,s)==true)
    {
        return dp[i][j]=0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int minans=INT_MAX;
    for(int k=i;k<j;k++)
    {
    	if(ispalindrome(i,k,s)==false)
        {
            continue;
        }
        int tempans= palpartitionmemoization(i,k,s,dp) + palpartitionmemoization(k+1,j,s,dp) + 1;
        minans=min(minans,tempans);
	}
	return dp[i][j]=minans;
}

int main()
{
	string str="ababbbabbababa";
	int n=str.length();
	int i=0,j=n-1;
	int ans1=palpartitionrecursion(i,j,str);
	cout<<"Minimum Partitions By Recursion:"<<ans1<<endl;
	vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
	int ans2=palpartitionmemoization(i,j,str,dp);
	cout<<"Minimum Partitions By Memoization:"<<ans2<<endl;
}

