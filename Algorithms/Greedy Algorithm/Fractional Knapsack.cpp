#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//comparator function to sort in value/weight order
static bool comparator(pair<double,int> a,pair<double,int> b)
{
    double r1=(double)a.first/a.second;
    double r2=(double)b.first/b.second;
    return r1>r2;
}

//Function to get the maximum total value in the knapsack.
double fractionalknapsack(int W, vector<int>&value, vector<int>&weight, int n)
{
    vector<pair<double,int>>v;
    for(int i=0;i<n;i++)
    {
        v.push_back({value[i],weight[i]});
    }
    //sort in descending order
    sort(v.begin(),v.end(),comparator);
    int currwt=0;
    double profit=0.0;
    //first = value , second = weight
    for(int j=0;j<n;j++)
    {
        //completely pick the item
        if(currwt+v[j].second<=W)
        {
            currwt+=v[j].second;
            profit+=v[j].first;
        }
        else
        {
            //remaining weight in knapsack
            int remwt=W-currwt;
            profit+=(v[j].first/v[j].second)*remwt;
            //since now we have completely filled our knapsack so no more space remains
            break;
        }
    }
    return profit;
}

int main()
{
	vector<int>value={60,100,120};
	vector<int>weight={10,20,30};
	int W=50;
	double ans=fractionalknapsack(W,value,weight,3);
	cout<<"Maximum Profit Is:"<<ans<<endl;
}
