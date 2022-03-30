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
		if(sum<k)
		{
			j++;
		}
		else if(sum>k)
		{
			//then we have to remove some elements from beginning which was contributing to sum
			while(sum>k)
			{
				sum-=v[i];
				i++;
			}
			j++;
		}
		else if(sum==k)
		{
			//storing the window size if greater than current window size
			maxsize=max(maxsize,(j-i+1));
			j++;
		}
	}
	cout<<"Size of Longest Subarray with sum k is:"<<maxsize<<endl;
}

