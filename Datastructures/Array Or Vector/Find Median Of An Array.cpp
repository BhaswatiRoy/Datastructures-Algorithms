#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int find_median(vector<int>&v)
{
	int n=v.size(),median;
	sort(v.begin(),v.end());
	//if n is even then median is mid-1+mid element
	if(n%2==0)
	{
		median=(v[n/2]+v[n/2-1])/2;
		return (int)median;
	}
	//if n is odd then median is mid element
	return v[n/2];
}

int main()
{
	vector<int>v={3,6,2,8,9,2};
	int ans=find_median(v);
	cout<<"Median Is:"<<ans<<endl;
}
