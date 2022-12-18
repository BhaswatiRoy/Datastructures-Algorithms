#include <bits/stdc++.h>
using namespace std;

void print(vector<pair<int,int>>&vp)
{
	for(int i=0;i<vp.size();i++)
	{
		cout<<vp[i].first<<" "<<vp[i].second<<endl;
	}
	cout<<endl;
}

//comparator function to sort in descending order
bool cmp(pair<int,int>a, pair<int,int>b)
{
	//comparing 1st values
	if(a.first>b.first)
	{
		return true;
	}
	//if 1st values are same then compare 2nd values
	else if(a.first==b.first)
	{
		//comparing 2nd values
		if(a.second>b.second)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
 
int main()
{
	vector<pair<int,int>>vp={{1,3},{2,3},{4,3},{1,6},{2,13}};
	print(vp);
	//sort automatically sorts in ascending order 
	//comparing first value then second value
	sort(vp.begin(),vp.end());
	print(vp);
	//cmp used to sort in descending order
	sort(vp.begin(),vp.end(),cmp);
	print(vp);
}
