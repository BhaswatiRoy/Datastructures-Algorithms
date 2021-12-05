#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void selectionsortasec(vector<int>v)
{
	//if we sort the entire array upto 2nd last element then automatically the whole array gets sorted
	//since we can not compare last element with any more elements ahead of it
	int n=v.size();
	for(int i=0;i<n-1;i++)
	{
		int min=i;
		for(int j=i+1;j<n;j++)
		{
			if(v[j]<v[min])
			{
				min=j;
			}
		}
		if(min!=i)
		{
			//if min value index and i index are dissimilar then swap
			int temp=v[min];
			v[min]=v[i];
			v[i]=temp;
		}
	}
}

void selectionsortdesc(vector<int>v)
{
	//if we sort the entire array upto 2nd last element then automatically the whole array gets sorted
	//since we can not compare last element with any more elements ahead of it
	int n=v.size();
	for(int i=0;i<n-1;i++)
	{
		int min=i;
		for(int j=i+1;j<n;j++)
		{
			if(v[j]>v[min])
			{
				min=j;
			}
		}
		if(min!=i)
		{
			//if min value index and i index are dissimilar then swap
			int temp=v[min];
			v[min]=v[i];
			v[i]=temp;
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
	selectionsortasec(v);
	cout<<"Ascending Order Sorted form is:";
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	selectionsortdesc(v);
	cout<<"Descending Order Sorted form is:";
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
}
