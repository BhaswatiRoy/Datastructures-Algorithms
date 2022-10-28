/*
In a sorted array target element will always be together like - 2 4 5 10 10 10 11 12 19
So if we find 1st and last occurence then we can find the range of presence of element

TC - O(nlogn), SC - O(1)
*/

int firstocc(int arr[], int n, int x)
{
        int start=0, end=n-1;
        int res=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            //if we get a match we will keep searching to left
            //so that we get leftmost index possible
            if(arr[mid]==x)
            {
                res=mid;
                end=mid-1;
            }
            else if(arr[mid]>x)
            {
                end=mid-1;
            }
            else if(arr[mid]<x)
            {
                start=mid+1;
            }
        }
        return res;
}

int lastocc(int arr[], int n, int x)
{
        int start=0, end=n-1;
        int res=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            //if we get a match we will keep searching to right
            //so that we get rightmost index possible
            if(arr[mid]==x)
            {
                res=mid;
                start=mid+1;
            }
            else if(arr[mid]>x)
            {
                end=mid-1;
            }
            else if(arr[mid]<x)
            {
                start=mid+1;
            }
        }
        return res;
}
		
int count(int arr[], int n, int x) 
{
	    int first=firstocc(arr,n,x);
	    int last=lastocc(arr,n,x);
	    if(first==-1)
	    {
	        return 0;
	    }
	    return (last-first+1);
}

