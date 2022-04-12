#include<bits/stdc++.h>
using namespace std;

vector<int>ds;

bool goalsubsequence(int idx,vector<int>&arr,int n,int sum,int goal)
{
	//base case is hit when we have ind as equal or more than n
	if(idx>=n)
	{
		if(sum==goal)
		{
			for(auto it=ds.begin();it!=ds.end();it++)
			{
				cout<<*it<<" ";
			}
			cout<<endl;
			return true;
		}
		else
		{
			return false;
		}
	}
	
	//take or pick the particular index (element added to subsequence)
	ds.push_back(arr[idx]);
	//add the element into the sum
	sum+=arr[idx];
	
	//if any of the recursion calls returns T then we will end the recursion call there itself
	
	//since we have completed for ind we will move to ind+1
	if(goalsubsequence(idx+1,arr,n,sum,goal)==true)
	{
		return true;
	}
	
	//to not pick the last element which we picked we have to remove then do recursive call
	ds.pop_back();
	//remove the element from the sum
	sum-=arr[idx];
	
	//not take or not pick the particular index (element not added to subsequence)
	if(goalsubsequence(idx+1,arr,n,sum,goal)==true)
	{
		return true;
	}
	
	//if none of the recursion calls returns T then finally return a F
	return false;
}

int main()
{
	vector<int>arr={1,2,1};
	int n=arr.size(),sum=0,goal=2;
	cout<<"One Possible Subsequence With Sum "<<goal<<":"<<endl;
	goalsubsequence(0,arr,n,sum,goal);
}
