#include<bits/stdc++.h>
using namespace std;

/*
if there is an element 0 in the array then that element is the subarray with 0 sum
if anywhere if prefix sum is 0 in the array then that subarray part has 0 sum

else 
  4  2  -3  1  6
<-x->
<------y----->
now subarray 2, -3, 1 has sum=0 so y-x=0 thus y=x and this concept is used
thus y and x both represents prefix sums so if we have same prefix sum value for 2 sections then that subarray part has 0 sum
*/

bool subArrayExists(vector<int>&arr, int n)
{
    vector<int>pf(n,0);
    pf[0]=arr[0];
	for(int i=1;i<n;i++)
	{
	    if(arr[i]==0)
	    {
	        return true;
	    }
	    pf[i]=pf[i-1]+arr[i];
	    if(pf[i]==0)
	    {
	        return true;
	    }
	}
    sort(pf.begin(),pf.end());
    for(int j=0;j<pf.size()-1;j++)
    {
        if(pf[j+1]==pf[j])
        {
            return true;
        }
    }
    return false;
}

int main()
{
	vector<int>arr={4,2,-3,1,6};
	int n=arr.size();
	bool ans=subArrayExists(arr,n);
	if(ans==true)
	{
		cout<<"Yes Subarray With Sum=0 Exists!"<<endl;
	}
	else
	{
		cout<<"No Subarray With Sum=0 Doesn't Exists!"<<endl;
	}
}
