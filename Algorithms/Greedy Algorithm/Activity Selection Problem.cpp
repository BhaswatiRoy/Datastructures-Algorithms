#include<iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Activity Selection Problem->
You are given n activities with their start and finish times.
Select the maximum number of activities that can be performed by a single person.
Assume that a person can only work on a single activity at a time
*/

int main() 
{
	vector<vector<int>>v={{10,20},{12,15},{20,30}};
	//sorting a 2d vector on basis of the 2nd value in each element
	sort(v.begin(),v.end(),[&](vector<int>&a,vector<int>&b)
	{
		return a[1]<b[1];
	});
	int count=1,end=v[0][1];
	//since we considered v[0][1] for comparing so we need not to take that anymore
	for(int i=1;i<v.size();i++)
	{
		//start time of next is greater than end time of current then we can choose that
		if(v[i][0]>=end)
		{
			count++;
			//assigning end time of choosen element as end
			end=v[i][1];
		}
	}
	cout<<count<<endl;
	return 0;
}

