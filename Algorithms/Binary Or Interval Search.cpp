#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int binarysearch(vector<int>v,int left,int right,int x)
{
	//iterating through the datastructure
	while(left<=right)
	{
		int mid=left+(right-left)/2;
		//element lies in midpoint of the datastructure
		if(v[mid]==x)
		{
			return mid;
		}
		//element lies in 2nd half of the datastructure
		else if(v[mid]<x)
		{
			left=mid+1;
		}
		//element lies in 1st half of the datastructure
		else if(v[mid]>x)
		{
			right=mid-1;
		}
	}
	//if nothing is found in the while loop then we will return -1
	return -1;
}

int main()
{
	vector<int>v={3,11,29,35,45,51,62,72,88,90};
	int x,output;
	cout<<"Enter the element you want to search:";
	cin>>x;
	int right=(v.size()-1);
	int left=0;
	output=binarysearch(v,left,right,x);
	if(output==-1)
	{
		cout<<"Element not found!"<<endl;
	}
	else
	{
		cout<<"Element found at "<<output<<" index"<<endl;
	}
}

