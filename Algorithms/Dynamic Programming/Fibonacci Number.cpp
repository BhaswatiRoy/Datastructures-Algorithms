#include<bits/stdc++.h>
using namespace std;

/*
Memoization-
TC -> O(n) {as we are linearly calculating the values for all elements like a skewed tree which is O(n) and rest have O(1) TC}
SC -> o(n) + O(n) {one for recursion stack space and another for the dp vector

Tabulation (without space optimization)-
TC -> O(n) {traversing all the elements to store value in dp vector}
SC -> O(n) {no extra recursion stack space is used only the dp vector}

Tabulation (with space optimization)-
TC -> O(n) {traversing all the elements to store value in dp vector}
SC -> O(1) {neither extra recursion stack space is used nor the dp vector}
*/

//top down approach
int fibonaccimemoization(int n,vector<int>&dp1)
{
	if(n<=1)
	{
		return n;
	}
	if(dp1[n]!=-1)
	{
		return dp1[n];
	}
	return dp1[n]=fibonaccimemoization(n-1,dp1)+fibonaccimemoization(n-2,dp1);
}

//down top approach (without space optimization)
int fibonaccitabulation1(int n,vector<int>&dp2)
{
	dp2[0]=0,dp2[1]=1;
	for(int i=2;i<=n;i++)
	{
		//ith fibonacci = prev1 + prev2
		dp2[i]=dp2[i-1]+dp2[i-2];
	}
	return dp2[n];
}

//down top approach (with space optimization)
int fibonaccitabulation2(int n)
{
	int prev2=0,prev1=1,curr;
	for(int i=2;i<=n;i++)
	{
		//ith fibonacci = prev1 + prev2
		curr=prev1+prev2;
		//as we proceed forward prev1 & prev2 also proceed
		prev2=prev1;
		prev1=curr;
	}
	return curr;
}

int main()
{
	int n;
	cout<<"Enter The Value Of n:";
	cin>>n;
	
	vector<int>dp1(n+1,-1);
	int ansmemo=fibonaccimemoization(n,dp1);
	cout<<"The Value Of nth Factorial By Memoization is:"<<ansmemo<<endl;

	
	vector<int>dp2(n+1,-1);
	int anstab1=fibonaccitabulation1(n,dp2);
	cout<<"The Value Of nth Factorial By Tabulation Without Space Optimization is:"<<anstab1<<endl;
	
	int anstab2=fibonaccitabulation2(n);
	cout<<"The Value Of nth Factorial By Tabulation With Space Optimization is:"<<anstab2<<endl;
}
