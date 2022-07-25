#include<bits/stdc++.h>
using namespace std;

/*
Count Target Filled Subarrays - subarrays that only has target value
Like if target is 1 subarrays possible - {0,0},{0,0,0}
for n continous 0's there can be n+(n-1)+(n-2)+....+1 subarray counts
just like for 1 continuous 0's there can be 1 subarray, for 2 continuos 0's there can be 2+1=3 subarrays
*/

long long targetfilledsubarray(vector<int>& nums,int target) 
{
    long long count=0,finalcount=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==target)
        {
            count++;
            finalcount+=count;
        }
        else
        {
            count=0;
        }
    }
    return finalcount;
}

int main()
{
    vector<int>nums={1,3,6,6,2,6,6,4};
    long long finalcount=targetfilledsubarray(nums,target);
    cout<<"Count of Total Target Filled Subarrays:"<<finalcount<<endl;
}
