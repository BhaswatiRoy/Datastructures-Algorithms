#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x,temp=-1;
	vector<int>v={55,62,7,11,173};
	cout<<"Enter the element you want to search:";
	cin>>x;
	//looping through the datastructure to find the element
	for(int i=0;i<v.size();i++)
	{
		if(v[i]==x)
		{
			cout<<"Element is at "<<i<<" position";
			temp=0;
			break;
		}
		else
		{
			continue;
		}
	}
	//condition for element not present in the datastructure
	if(temp==-1)
	{
		cout<<"Element not found"<<endl;
	}
}
