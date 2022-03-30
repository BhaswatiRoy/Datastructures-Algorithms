#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() 
{
	int i;
	
	pair<int,int>p1(4,5);
	cout<<p1.first<<" "<<p1.second<<endl;
	
	pair<float,int>p2=make_pair(1.2,5);
	cout<<p2.first<<" "<<p2.second<<endl;
	
	pair<int,int>p3[4];
	for (i=0;i<4;i++)
	{
		cin>>p3[i].first>>p3[i].second;
	}
	cout<<endl;
	for (i=0;i<4;i++)
	{
		cout<<p3[i].first<<" "<<p3[i].second<<endl;
	}
	
    return 0;
}
