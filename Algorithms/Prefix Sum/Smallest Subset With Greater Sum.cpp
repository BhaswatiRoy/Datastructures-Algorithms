#include<bits/stdc++.h>
using namespace std;

/*
Smallest Subset with Greater Sum  -
We need to find the subset with smallest number of elements so that their sum will be greater than sum of rest of the elements of array
*/

int minsubset(vector<int>&Arr,int N)
{
	//if no of elements is <=1 then entire array elements will be needed to form a subset
    if(N<=1)
    {
        return N;
    }
    //subset is needed so we can change orders
    sort(Arr.begin(),Arr.end(),greater<int>());
    long long totalsum=0,subsetsum=0;
    int count=0;
    //prefix sum computed for entire array
    for(int i=0;i<N;i++)
    {
        totalsum+=Arr[i];
    }
    //if total sum is 0 then we need all the elements to form subset
    if(totalsum==0)
    {
        return N;
    }
    //subset sum computed starting from largest element and comparing with totalsum except taken elemenrs
    for(int j=0;j<N;j++)
    {
        subsetsum+=Arr[j];
        count++;
        totalsum-=Arr[j];
        if(subsetsum>totalsum)
        {
            return count;
        }
    }
    return -1;
}

int main()
{
	vector<int>Arr={4,3,1,0,2};
	int N=Arr.size();
	int size=minsubset(Arr,N);
	cout<<"Size Of Smallest Subset With Greater Sum Is:"<<size<<endl;
}
