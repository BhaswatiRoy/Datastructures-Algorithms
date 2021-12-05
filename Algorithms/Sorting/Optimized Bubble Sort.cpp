#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//optimized bubble sort stops the sorting once the datastructure is sorted
//if the datastructure is already sorted then flag=false so we break out of the loop

void bubblesortasec(vector<int>&v)
{
	int temp,n=v.size(),flag=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<(n-i-1);j++)
		{
			if(v[j]>v[j+1])
			{
				flag=true;
				temp=v[j];
				v[j]=v[j+1];
				v[j+1]=temp;
			}
		}
		//as soon as no sorting occurs in 1 iteration then we will break out
		//no sorting after checking means the datastructure is sorted
		if(flag==false)
		{
			break;
		}
	}
}

void bubblesortdesc(vector<int>&v)
{
	int temp,n=v.size(),flag=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<(n-i-1);j++)
		{
			if(v[j]<v[j+1])
			{
				flag=true;
				temp=v[j];
				v[j]=v[j+1];
				v[j+1]=temp;
			}
		}
		//as soon as no sorting occurs in 1 iteration then we will break out
		//no sorting after checking means the datastructure is sorted
		if(flag==false)
		{
			break;
		}
	}
}

int main() 
{
	vector<int>v={34,1,25,67,89,16};
	cout<<"Unsorted form is:";
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	bubblesortasec(v);
	cout<<"Ascending Order Soted Form is:";
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	bubblesortdesc(v);
	cout<<"Descending Order Soted Form is:";
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
}

