#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	vector<int>v={-1,4,7,2};
	//declaring start point of subarray
	for(int i=0;i<v.size();i++)
	{
		//declaring end point of subarray
		for(int j=0;j<v.size();j++)
		{
			//looping to print all elements within range i to j
			for(int k=i;k<=j;k++)
			{
				cout<<v[k]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}

