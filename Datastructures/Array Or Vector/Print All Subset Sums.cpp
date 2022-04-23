#include<bits/stdc++.h>
using namespace std;

/*
Subset Sum ->
We have to store sum of elements of all subsets and store it in vector
Here we are not considering an element more than once
TC is (2^n) + (2^n)log(2^n) = (2^n)log(2^n)
*/

void subset(int idx,int sum,vector<int>&arr,vector<int>&ans)
{
	if(idx==arr.size())
	{
		ans.push_back(sum);
		return;
	}
	//picking the element and adding it to sum
	subset(idx+1,sum+arr[idx],arr,ans);
	
	//not picking the element and thus not adding it to sum
	subset(idx+1,sum,arr,ans);
}

int main()
{
	vector<int>arr={5, 2, 1};
	vector<int>ans;
	subset(0,0,arr,ans);
	sort(ans.begin(),ans.end());
	
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}

