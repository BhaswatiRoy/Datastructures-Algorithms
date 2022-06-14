#include<bits/stdc++.h>
using namespace std;

/*
This question might look like being solvable by Sliding Window but will not give right answer as constraint is given -1000 <= nums[i] <= 1000.
So there is no guarantee that if we reduce size of window from back by doing i++ then we will reduce sum also as -ve numbers are also included.
*/

//Brute Force approach - TC - O(n^2) (gives TLE)
int subarraysumcountbrute(vector<int>&nums, int k) 
{
    int sum=0,count=0,n=nums.size();
    for(int i=0;i<n;i++)
    {
        //take current element at i as sum
        sum=nums[i];
        if(sum==k)
        {
            count++;
        }
        for(int j=i+1;j<n;j++)
        {
            //increment sum for each element at j
            sum+=nums[j];
            if(sum==k)
            {
                count++;
            }
        }
    }
    return count;
}

//Prefix Sum + Hashing approach - O(n) (don't give TLE)
int subarraysumcountoptimal(vector<int>&nums, int k) 
{
    int count=0,sum=0,n=nums.size();
    //map to store prefix sum,count 
    unordered_map<int,int>mp;
    //suppose we have 1,1,1 and k=3 in that case sum=1+1+1=3 thus sum-k=0 and 0 might not be present always which is why we could miss counting it
    mp[0]=1;
    for(int i=0;i<n;i++)
    {
        sum+=nums[i];
        //no of occurences is count of those prefix sum arrays in the map similar to 2 sum approach
        count+=mp[sum-k];
        //store that sum in the map
        mp[sum]++;
    }
    return count;
}

int main()
{
	vector<int>v={-1,-1,1,1,2,-2};
	int k=0;
	cout<<"Subarray Count With Sum Equal To k By Brute Force:"<<subarraysumcountbrute(v,k)<<endl;
	cout<<"Subarray Count With Sum Equal To k By Optimal:"<<subarraysumcountbrute(v,k)<<endl;
}
