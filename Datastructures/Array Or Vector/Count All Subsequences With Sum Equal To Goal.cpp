#include<bits/stdc++.h>
using namespace std;

vector<int>ds;

int goalsubsequence(int idx,vector<int>&arr,int n,int sum,int goal)
{
	//base case is hit when we have ind as equal or more than n
	if(idx>=n)
	{
		if(sum==goal)
		{
			//everytime condition is satisfied then we will return 1 to count 
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	//take or pick the particular index (element added to subsequence)
	ds.push_back(arr[idx]);
	//add the element into the sum
	sum+=arr[idx];
	
	//since we have completed for ind we will move to ind+1
	int l=goalsubsequence(idx+1,arr,n,sum,goal);
	
	//to not pick the last element which we picked we have to remove then do recursive call
	ds.pop_back();
	//remove the element from the sum
	sum-=arr[idx];
	
	//not take or not pick the particular index (element not added to subsequence)
	int r=goalsubsequence(idx+1,arr,n,sum,goal);
	
	return l+r;
}

int main()
{
	vector<int>arr={1,2,1};
	int n=arr.size(),sum=0,goal=2;
	int count=goalsubsequence(0,arr,n,sum,goal);
	cout<<"Total Count Of Subsequences With Sum Equal To Goal:";
	cout<<count<<endl;
}
