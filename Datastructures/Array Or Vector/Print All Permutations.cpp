#include<bits/stdc++.h>
using namespace std;

void allpermutations(vector<int>&ds,vector<int>&nums,vector<vector<int>>&ans,unordered_map<int,int>&freq)
{
	if(ds.size()==nums.size())
	{
		ans.push_back(ds);
		return;
	}
	for(int i=0;i<nums.size();i++)
	{
		//if any element is not present in the map
		if(freq[i]==0)
		{
			//push the element 
			ds.push_back(nums[i]);
			//set the element to 1 in map
			freq[i]=1;
			//recursively create permutations with that element
			allpermutations(ds,nums,ans,freq);
			//set the element to 0 in map
			freq[i]=0;
			//then pop that element
			ds.pop_back();
		}
	}
}

vector<vector<int>> permutations(vector<int>&nums)
{
	vector<vector<int>>ans;
	vector<int>ds;
	unordered_map<int,int>freq;
	for(int i=0;i<nums.size();i++)
	{
		freq[i]=0;
	}
	allpermutations(ds,nums,ans,freq);
	return ans;
}

int main()
{
	vector<int>nums={1,2,3};
	vector<vector<int>>ans=permutations(nums);
	for(int p=0;p<ans.size();p++)
	{
		for(int q=0;q<ans[p].size();q++)
		{
			cout<<ans[p][q]<<" ";
		}
		cout<<endl;
	}
}
