/*
We will use binary search to solve this.
If we get a match we can search on left part of array to get left most array - First Occurence
If we get a match we can search on right part of array to get left most array - Last Occurence

TC - O(logn), SC - O(1)
*/

long long firstocc(vector<long long> v, long long x)
{
        int n=v.size();
        int start=0, end=n-1;
        int res=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            //if we get a match we will keep searching to left
            //so that we get leftmost index possible
            if(v[mid]==x)
            {
                res=mid;
                end=mid-1;
            }
            else if(v[mid]>x)
            {
                end=mid-1;
            }
            else if(v[mid]<x)
            {
                start=mid+1;
            }
        }
        return res;
}
long long lastocc(vector<long long> v, long long x)
{
        int n=v.size();
        int start=0, end=n-1;
        int res=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            //if we get a match we will keep searching to right
            //so that we get rightmost index possible
            if(v[mid]==x)
            {
                res=mid;
                start=mid+1;
            }
            else if(v[mid]>x)
            {
                end=mid-1;
            }
            else if(v[mid]<x)
            {
                start=mid+1;
            }
        }
        return res;
}
pair<long,long> indexes(vector<long long> v, long long x)
{
        long long first=firstocc(v,x);
        long long last=lastocc(v,x);
        return {first,last};
}
