#include<bits/stdc++.h>
using namespace std;

/*
We try to pick least price candies to calculate for min amount and highest price candies to calculate for max amount
Every time we pick a candy we do i++ to pick next candy price and do j-=k to count the free candies already taken
For minamt we sort and use the array and for maxamt we revsort and use the array
*/

vector<int>candystore(int candies[], int N, int K)
{
    sort(candies,candies+N);
    int maxamt=0,minamt=0;
    int i=0,j=N-1;
    while(i<=j)
    {
        minamt+=candies[i];
        //shift 1 forward to count cost
        i++;
        //shift k backward to count free candies already picked
        j-=K;
    }
    //reversing to do exact opposite of last case
    reverse(candies,candies+N);
    i=0,j=N-1;
    while(i<=j)
    {
        maxamt+=candies[i];
        //shift 1 forward to count cost
        i++;
        //shift k backward to count free candies already picked
        j-=K;
    }
    return {minamt,maxamt};
}

int main()
{
	int candies[]={3,2,1,4};
	int N=4,K=2;
	vector<int>ans=candystore(candies,N,K);
	cout<<ans[0]<<" "<<ans[1]<<endl;
}
