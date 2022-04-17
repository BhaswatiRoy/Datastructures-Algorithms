#include<bits/stdc++.h>
using namespace std;

/*  
Combination Sum 1 ->
We have to print all possible combinations whose sum is target
Also here we can consider one element multiple times
TC of brute force approach is (2^n)*k*logn {extra logn due to insertion operation in set)
TC of optimized approach is (2^n)*k
{k in both cases is due to pushing one subsquence in final vector}
*/

//brute force function 1
void findcombinationbrute(int idx,int target,vector<int>&candidates,vector<vector<int>>&ans,vector<int>&ds)
{
    if(idx==candidates.size())
    {
        if(target==0)
        {
            ans.push_back(ds);
        }
        return;
    }
    if(candidates[idx]<=target)
    {
        ds.push_back(candidates[idx]);
        findcombinationbrute(idx+1,target-candidates[idx],candidates,ans,ds);
        ds.pop_back();
    }
    findcombinationbrute(idx+1,target,candidates,ans,ds);
}

//brute force function 2
vector<vector<int>> combinationsum2brute(vector<int>&candidates, int target) 
{
    vector<vector<int>>ans;
    vector<int>ds;
    //sorting is done as we want subarrays with elements in ordered format
    sort(candidates.begin(),candidates.end());
    findcombinationbrute(0,target,candidates,ans,ds);
    //using set to remove duplicate vector elements
    set<vector<int>>st;
    for(auto it=ans.begin();it!=ans.end();it++)
    {
        st.insert(*it);
    }
    ans.clear();
    for(auto it=st.begin();it!=st.end();it++)
    {
        ans.push_back(*it);
    }
    return ans;
}

//optimal function 1
void findcombinationoptimal(int idx,int target,vector<int>&candidates,vector<vector<int>>&ans,vector<int>&ds)
{
	if(target==0)
	{
		ans.push_back(ds);
		return;
	}
	for(int i=idx;i<candidates.size();i++)
	{
		if(candidates[i]>target) 
		{
			break;
		}
		if(i>idx && candidates[i]==candidates[i-1])
		{
			continue;
		}
		ds.push_back(candidates[i]);
		findcombinationoptimal(i+1,target-candidates[i],candidates,ans,ds);
		ds.pop_back();
	}
}

//optimal function 2
vector<vector<int>> combinationsum2optimal(vector<int>&candidates, int target)
{
	sort(candidates.begin(),candidates.end());
	vector<vector<int>>ans;
	vector<int>ds;
	findcombinationoptimal(0,target,candidates,ans,ds);
}

int main()
{
	vector<int>candidates={2,5,2,1,2};
	vector<vector<int>>finalans1,finalans2;
	int target=5;
	finalans1=combinationsum2brute(candidates,target);
	cout<<"Brute Force"<<endl;
	cout<<"All combinations with target value same element not considered more than once:"<<endl;
	for(int i=0;i<finalans1.size();i++)
	{
		for(int j=0;j<finalans1[i].size();j++)
		{
			cout<<finalans1[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	finalans2=combinationsum2brute(candidates,target);
	cout<<"Optimal"<<endl;
	cout<<"All combinations with target value same element not considered more than once:"<<endl;
	for(int i=0;i<finalans2.size();i++)
	{
		for(int j=0;j<finalans2[i].size();j++)
		{
			cout<<finalans2[i][j]<<" ";
		}
		cout<<endl;
	}
}
