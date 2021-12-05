#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bubblesortasec(vector<int>&v)
{
	int temp,n=v.size();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<(n-i-1);j++)
		{
			if(v[j]>v[j+1])
			{
				temp=v[j];
				v[j]=v[j+1];
				v[j+1]=temp;
			}
		}
	}
}

void bubblesortdesc(vector<int>&v)
{
	int temp,n=v.size();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<(n-i-1);j++)
		{
			if(v[j]<v[j+1])
			{
				temp=v[j];
				v[j]=v[j+1];
				v[j+1]=temp;
			}
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
	cout<<"Ascending Order Sorted Form is:";
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	bubblesortdesc(v);
	cout<<"Descending Order Sorted Form is:";
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
}

