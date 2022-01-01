#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int partitionasec(vector<int>&v,int s,int e)
{
	//select end element as partition element
	int pivot=v[e];
	int pindex=s;
	//we are not considering last element as it is taken as pivot
	for(int i=s;i<e;i++)
	{
		//any element smaller than pivot will be swapped with the left element and the index is marked
		if(v[i]<pivot)
		{
			int temp=v[i];
			v[i]=v[pindex];
			v[pindex]=temp;
			pindex++;
		}
	}
	int temp=v[e];
	v[e]=v[pindex];
	v[pindex]=temp;
	//finally pivot comes to the proper position of the sorted vector
	//in end we need to return the pivot index position
	return pindex;
}

int partitiondesc(vector<int>&v,int s,int e)
{
	//select end element as partition element
	int pivot=v[e];
	int pindex=s;
	//we are not considering last element as it is taken as pivot
	for(int i=s;i<e;i++)
	{
		//any element greater than pivot will be swapped with the left element and the index is marked
		if(v[i]>pivot)
		{
			int temp=v[i];
			v[i]=v[pindex];
			v[pindex]=temp;
			pindex++;
		}
	}
	int temp=v[e];
	v[e]=v[pindex];
	v[pindex]=temp;
	//finally pivot comes to the proper position of the sorted vector
	//in end we need to return the pivot index position
	return pindex;
}


void quicksortasec(vector<int>&v,int s,int e)
{
	if(s<e)
	{
		//the partition function returns an index which will be partition index for next call
		int p=partitionasec(v,s,e);
		//recursive quicksort call for left partition
		quicksortasec(v,s,p-1);
		//recursive quicksort call for right partition
		quicksortasec(v,p+1,e);
	}
}

void quicksortdesc(vector<int>&v,int s,int e)
{
	if(s<e)
	{
		//the partition function returns an index which will be partition index for next call
		int p=partitiondesc(v,s,e);
		//recursive quicksort call for left partition
		quicksortdesc(v,s,p-1);
		//recursive quicksort call for right partition
		quicksortdesc(v,p+1,e);
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
	quicksortasec(v,0,n-1);
	cout<<"Ascending Order Sorted Form is:";
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	quicksortdesc(v,0,n-1);
	cout<<"Descending Order Sorted Form is:";
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
