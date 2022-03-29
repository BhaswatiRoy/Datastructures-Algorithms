#include<bits/stdc++.h>
using namespace std;

/* Fixed Size Window Sliding Window Problem - Maximum Sum Subarray of size k */

int main()
{
	vector<int>v={3,6,2,7,8,4,5};
	int i=0,j=0,k,n=v.size();
	cout<<"Enter the size of window:";
	cin>>k;
	int sum=0,maxsum=0;
	//trying to attain a window of size k
	while(j<n)
	{
		if(j-i+1<k)
		{
			sum+=v[j];
			j++;
		}
		else if(j-i+1==k)
		{
			sum+=v[j];
			break;
		}
	}
	//cout<<sum<<endl;
	maxsum=sum;
	while(j<n)
	{
		sum-=v[i];
		sum+=v[j+1];
		maxsum=max(sum,maxsum);
		i++;
		j++;
	}
	cout<<"Maximum Sum Subarray of size "<<k<<" is:"<<maxsum;
}

