#include<bits/stdc++.h>
using namespace std;

/*
Maximum Absolute Sum of Any Subarray-
Finding the maximum absolute sum which can be sum of some +ve integers or some -ve integers
So we need to use Kadane Algorithm twice once for max sum & min sum
Then we will take abs(min) and return max of the both
*/

int maxsubarraysum(vector<int>& nums)
{
    int currsum=0,maxsum=INT_MIN;
    for(int i=0;i<nums.size();i++)
    {
        currsum+=nums[i];
        if(currsum>maxsum)
        {
            maxsum=currsum;
        }
        if(currsum<0)
        {
            currsum=0;
        }
    }
    return maxsum;
}

int minsubarraysum(vector<int>&nums)
{
    int currsum=0,minsum=INT_MAX;
    for(int j=0;j<nums.size();j++)
    {
        currsum+=nums[j];
        if(currsum<minsum)
        {
            minsum=currsum;
        }
        if(currsum>0)
        {
            currsum=0;
        }
    }
    return minsum;
}

int maxabsolutesum(vector<int>& nums) 
{
    int maxval=maxsubarraysum(nums);
    int minval=minsubarraysum(nums);
        
    return max(maxval,abs(minval));
}

int main()
{
	vector<int>nums={2,-5,1,-4,3,-2};
	int maxabssum=maxabsolutesum(nums);
	cout<<"Maximum Possible Absolute Sum is:"<<maxabssum<<endl;
}
