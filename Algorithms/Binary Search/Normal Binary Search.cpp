/*
Every time we divide the array into 3 parts - left of mid, mid, right of mid
Thus we reduce the space to search the element by half everytime - n, n/2, n/4, ...... 

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
                end=mid-1;
            }
            else if(nums[mid]<target)
            {
                start=mid+1;
            }
        }
        return -1;
}
