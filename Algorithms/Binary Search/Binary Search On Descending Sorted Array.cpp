/*
Since array is sorted in descending order, so if target is greater than mid so we go to left of mid.
Similarly if target is smaller than mid o we go to right of mid.
All of this is opposite to normal sorted array which is ascending order sorted.

TC - O(logn), SC - O(1)
*/

int search(vector<int>& nums, int target) 
{
        int start=0, end=nums.size()-1;
        while(start<=end)
        {
            //this results to same i.e (start+end)/2 but written in different way
            //if start & end are near to int max value then there is a chance of int overflow
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target)
            {
                start=mid+1;
            }
            else if(nums[mid]<target)
            {
                end=mid-1;
            }
        }
        return -1;
}
