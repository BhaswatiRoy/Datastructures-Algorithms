#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() 
{
	vector<int>v={-1,4,7,2};
	int n=v.size();
	int maxsum=INT_MIN;
	//i denotes starting point
	for(int i=0;i<n;i++)
	{
		//j denotes ending point
		for(int j=i;j<n;j++)
		{
			int sum=0;
			//k denotes iteration from starting to ending point
			for(int k=i;k<=j;k++)
			{
				//finding subarray sum
				sum+=v[k];
			}
			//keep updating maxsum variable with maximum value of sum
			maxsum=max(maxsum,sum);
		}
	}
	cout<<"Maximum Sum Subarray Is:"<<maxsum<<endl;
}
