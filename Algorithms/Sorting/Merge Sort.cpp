#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void mergeintervalasec(vector<int>&v,int s,int m,int e) 
{
	vector<int>temp;
	int i,j;
	i=s;
	j=m+1;
	while (i<=m && j<=e) 
	{
		if (v[i]<=v[j]) 
		{
			temp.push_back(v[i]);
			i++;
		}
		else 
		{
			temp.push_back(v[j]);
			j++;
		}
	}
	while(i<=m)
	{
		temp.push_back(v[i]);
		i++;
	}
	while(j<=e) 
	{
		temp.push_back(v[j]);
	    j++;
	}
	for(int i=s;i<=e;++i)
	{
		v[i]=temp[i-s];
	}
}

void mergeintervaldesc(vector<int>&v,int s,int m,int e) 
{
	vector<int>temp;
	int i,j;
	i=s;
	j=m+1;
	while (i<=m && j<=e) 
	{
		if (v[i]>=v[j]) 
		{
			temp.push_back(v[i]);
			i++;
		}
		else 
		{
			temp.push_back(v[j]);
			j++;
		}
	}
	while(i<=m)
	{
		temp.push_back(v[i]);
		i++;
	}
	while(j<=e) 
	{
		temp.push_back(v[j]);
		j++;
	}
	for(int i=s;i<=e;++i)
	{
		v[i]=temp[i-s];
	}
}

void mergesortasec(vector<int>&v,int s,int e) 
{
	if(s<e) 
	{
		int m=(s+e)/2;
		mergesortasec(v,s,m);
		mergesortasec(v,m+1,e);
		mergeintervalasec(v,s,m,e);
	}
}

void mergesortdesc(vector<int>&v,int s,int e) 
{
	if(s<e) 
	{
		int m=(s+e)/2;
		mergesortdesc(v,s,m);
		mergesortdesc(v,m+1,e);
		mergeintervaldesc(v,s,m,e);
	}
}

int main() 
{
	vector<int>v={4,6,1,2,7};
	cout<<"Unsorted form is:";
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	int n=v.size();
	mergesortasec(v,0,n-1);
	cout<<"Ascending Order Sorted Form is:";
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	mergesortdesc(v,0,n-1);
	cout<<"Descending Order Sorted Form is:";
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
