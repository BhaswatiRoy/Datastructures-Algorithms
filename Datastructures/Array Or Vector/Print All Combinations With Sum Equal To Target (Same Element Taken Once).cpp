#include<bits/stdc++.h>
using namespace std;

/*  
Combination Sum 1 ->
We have to print all possible combinations whose sum is target
Also here we can consider one element multiple times
*/

void findcombination(int ind,int target,vector<int>&candidates,vector<vector<int>>&ans,vector<int>&ds)
{
	//if last index is reached
	if(ind==candidates.size())
	{
		//has the target value been achieved by the current combination
		if(target==0)
		{
			//push the datastructure into the final datastructure
			ans.push_back(ds);
		}
		return;
	}
	//pick up elements if less than or equal to reduced target
	if(candidates[ind]<=target)
	{
		ds.push_back(candidates[ind]);
		//take the same element again because we can take 1 element multiple times
		//we are reducing the target if we are picking any element
		findcombination(ind,target-candidates[ind],candidates,ans,ds);
		//after recursion call with picking ends we can remove the element before going to not pick condition
		ds.pop_back();
	}
	//not pick an element so index is increases and target is same
	findcombination(ind+1,target,candidates,ans,ds);
}

vector<vector<int>> combinationsum1brute(vector<int>&candidates,int target)
{
	vector<vector<int>>ans;
	vector<int>ds;
	findcombination(0,target,candidates,ans,ds);
	return ans; 
}

int main()
{
	vector<int>candidates={2,3,6,7};
	vector<vector<int>>finalans;
	int target=7;
	finalans=combinationsum1brute(candidates,target);
	cout<<"All combinations with target value same element considered more than once:"<<endl;
	for(int i=0;i<finalans.size();i++)
	{
		for(int j=0;j<finalans[i].size();j++)
		{
			cout<<finalans[i][j]<<" ";
		}
		cout<<endl;
	}
}
