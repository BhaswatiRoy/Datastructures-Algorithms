#include<bits/stdc++.h>
using namespace std;

/*
Subsets 1 ->
We have to print all subsets of the array which has unique elements
We only need to print the unique subsets
TC is (2^n) 
*/

void subset(int idx,vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans)
{
    if(idx==nums.size())
    {
        ans.push_back(ds);
        return;
    }
        //picking the current index in subset combination
    ds.push_back(nums[idx]);
        
    //unique elements and we can't have duplicate subsets so idx+1
    subset(idx+1,nums,ds,ans);
        
    //not picking the current index in subset combination
    ds.pop_back();
        
    //moving to next index by not picking so idx+1
    subset(idx+1,nums,ds,ans);
}

int main()
{
	vector<int>nums={5, 2, 1};
	vector<int>ds;
	vector<vector<int>>ans;
	subset(0,nums,ds,ans);
	
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

