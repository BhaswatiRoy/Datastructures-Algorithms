#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void insertionsortasec(vector<int>&v)
{
	int key,j=0;
	for(int i=0;i<v.size();i++)
	{
		//storing the current value in temporary variable key
		key=v[i];
		j=i-1;
		while(j>=0 && v[j]>key)
		{
			//swap values
			v[j+1]=v[j];
			j--;
		}
		//j is decremented and then value is stored
		v[j+1]=key;
	}
}

void insertionsortdesc(vector<int>&v)
{
	int key,j=0;
	for(int i=0;i<v.size();i++)
	{
		//storing the current value in temporary variable key
		key=v[i];
		j=i-1;
		while(j>=0 && v[j]<key)
		{
			//swap values
			v[j+1]=v[j];
			j--;
		}
		//j is decremented and then value is stored
		v[j+1]=key;
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
	cout<<"Asecending Order Sorted form is:";
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
