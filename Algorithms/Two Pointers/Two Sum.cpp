#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Find if sum of 2 numbers in the vector is equal to the targetted sum
*/

bool pairsum(vector<int>&v,int n,int target)
{
	int low=0,high=n-1;
	while(low<high)
	{
		if(v[low]+v[high]==target)
		{
			cout<<v[low]<<" & "<<v[high]<<endl;
			return true;
		}
		else if(v[low]+v[high]<target)
		{
			low++;
		}
		else if(v[low]+v[high]>target)
		{
			high--;
		}
	}
	return false;
}

int main() 
{
	vector<int>v={2,4,7,11,14,16,20,21};
	int target=31;
	int n=v.size();
	pairsum(v,n,target);
}

