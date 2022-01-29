#include<bits/stdc++.h>
using namespace std;

vector<int>ds;

void printallsubsequence(int idx,vector<int>&arr,int n)
{
	//base case is hit when we have ind as n
	if(idx==n)
	{
		for(auto it=ds.begin();it!=ds.end();it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
		return;
	}
	
	//take or pick the particular index (element added to subsequence)
	ds.push_back(arr[idx]);
	//since we have completed for ind we will move to ind+1
	printallsubsequence(idx+1,arr,n);
	ds.pop_back();
	
	//not take or not pick the particular index (element not added to subsequence)
	printallsubsequence(idx+1,arr,n);
}

int main()
{
	vector<int>arr={3,1,2};
	int n=arr.size();
	printallsubsequence(0,arr,n);
}
