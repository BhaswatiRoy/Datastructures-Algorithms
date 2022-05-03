#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Prefix Sum is the cummulative sum of any element position-(i,j)
v={3,6,2,8,9,2} -> pf={3,9,11,19,28,30}
pf[i] denotes sum of 1st to ith element
pf[i]=pf[i-1]+v[i]
*/

void prefixsum(vector<int>&v,vector<int>&pf,int n)
{
	//adding 1st element of the actual vector as 1st element of the prefix sum vector
	pf[0]=v[0];
	//setting values from 2nd element to end
	for(int i=1;i<=n;i++)
	{
		pf[i]=pf[i-1]+v[i];
	}
}

int main()
{
	vector<int>v={3,6,2,8,9,2};
	int n=v.size()-1;
	vector<int>pf(n,0);
	prefixsum(v,pf,n);
	int left=1,right=3;
	cout<<pf[right]-pf[left-1]<<endl;
}
