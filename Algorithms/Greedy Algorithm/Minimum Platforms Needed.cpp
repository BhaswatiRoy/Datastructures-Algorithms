#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int findplatform(vector<int>&arr,vector<int>&dep, int n)
{
    int platformcount=1,maxplatformcount=1;
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    //we start with comparing arrival of 2nd train & departure of 1st train
    int i=1,j=0;
    while(i<n && j<n)
    {
    	//arrival time of next train is less or equal to departure time of one train
    	if(arr[i]<=dep[j])
    	{
    	    //counting current platforms occupied together
    	    platformcount++;
    	    //finding max no of platforms occupied at any momemnt of time
    	    maxplatformcount=max(platformcount,maxplatformcount);
    	    //incrementing the arrival time iterator
    	    i++;
    	}
    	//arrival time of next train is more than departure time of one train
    	else if(arr[i]>dep[j])
    	{
    	    //reducing count of 1 platform as 1 train departues before another comes
    	    platformcount--;
    	    //incrementing the departure time iterator
    	    j++;
    	}
    }
    return maxplatformcount;
}

int main()
{
	vector<int>arr={900,940,950,1100,1500,1800};
	vector<int>dep={910, 1200, 1120, 1130, 1900, 2000};
	int n=arr.size();
	int ans=findplatform(arr,dep,n);
	cout<<"Minimum Number Of Platforms Needed:"<<ans<<endl;
}
