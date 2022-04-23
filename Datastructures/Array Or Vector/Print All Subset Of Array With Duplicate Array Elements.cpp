#include<bits/stdc++.h>
using namespace std;

/*
Subsets 1 ->
We have to print all subsets of the array which has unique elements
We only need to print the unique subsets in any order
TC of brute force approach is (2^n)*k + (2^n)*k*log(2^n) = (2^n)log(2^n) {extra logn due to insertion operation in set}
TC of optimized approach is (2^n)*k
{k in both cases is due to pushing one subsquence in final vector}
*/

void findsubset2brute(int idx,vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans)
{
    if(idx==nums.size())
    {
        ans.push_back(ds);
        return;
    }
        //picking the current index in subset combination
    ds.push_back(nums[idx]);
        
    //unique elements and we can't have duplicate subsets so idx+1
    findsubset2brute(idx+1,nums,ds,ans);
        
    //not picking the current index in subset combination
    ds.pop_back();
        
    //moving to next index by not picking so idx+1
    findsubset2brute(idx+1,nums,ds,ans);
}

void subset2brute(int idx,vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans)
{
	findsubset2brute(idx,nums,ds,ans);
	set<vector<int>>st;
	for(int i=0;i<ans.size();i++)
	{
		st.insert(ans[i]);
	}
	ans.clear();
	for(auto it=st.begin();it!=st.end();it++)
	{
		ans.push_back(*it);
	}
	cout<<endl;
}

void findsubset2optimal(int idx,vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans)
{
	//finally add all possible subsets inside the final datastructure
	ans.push_back(ds);
	for(int i=idx;i<nums.size();i++)
	{
		//at i==idx we get the 1st occurence of the duplicate elemnts so we can pick that
		//but after that when i!=idx we have same elements later so we can't pick them
		if(i!=idx && nums[i]==nums[i-1])
		{
			//don't use that element
			continue;
		}
		//add into the subset 
		ds.push_back(nums[i]);
		//then recursively call the function for next index i+1
		findsubset2optimal(i+1,nums,ds,ans);
		//remove the element added before we go to next subsets
		ds.pop_back();
	}
}

void subset2optimal(int idx,vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans)
{
	//sorting is important then only duplicate elements will be in adjacent indices
	//thus we can compare nums[i] & nums[i-1]
	sort(nums.begin(),nums.end());
	findsubset2optimal(0,nums,ds,ans);
}

int main()
{
	vector<int>nums={5,2,1};
	vector<int>ds;
	vector<vector<int>>ans;
	subset2brute(0,nums,ds,ans);
	cout<<"Brute Force"<<endl;
	cout<<"All Unqiue Subsets Of Array With Duplicate Elements:"<<endl;
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	ans.clear();
	
	subset2optimal(0,nums,ds,ans);
	cout<<"Optimal"<<endl;
	cout<<"All Unqiue Subsets Of Array With Duplicate Elements:"<<endl;
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}

