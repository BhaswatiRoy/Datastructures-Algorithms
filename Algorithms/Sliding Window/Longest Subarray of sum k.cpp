#include<bits/stdc++.h>
using namespace std;

/* Variable Size Window Sliding Window Problem - Longest Subarray of sum k */

int main()
{
	vector<int>v={4,1,1,1,2,3,5};
	int i=0,j=0,k,n=v.size();
	cout<<"Enter maximum sum of the subarray needed:";
	cin>>k;
	int sum=0,maxsize=0;
	while(j<n)
	{
		sum+=v[j];
		//while sum is more than k then keep removing elements & increment i 
		while(sum>k)
		{
			sum-=v[i];
			i++;
		}
		//if we get required sum then increment size
		if(sum==k)
		{
			//storing the window size if greater than current window size
			maxsize=max(maxsize,(j-i+1));
		}
		j++;
	}
	cout<<"Size of Longest Subarray with sum k is:"<<maxsize<<endl;
}

