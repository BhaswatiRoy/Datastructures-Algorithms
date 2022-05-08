#include<bits/stdc++.h>
using namespace std;

/*
We try to finish those activities first which have lowest ending time 
Also we check if next job has starting time which is greater than ending time of last job then only we can perform that
TC -> n + nlogn + n {we are storing then sorting then traversing}
*/

int maxmeetings(vector<int>&start,vector<int>&end,int n)
{
    vector<pair<int,int>>activity;
    for(int i=0;i<n;i++)
    {
        //0th index=end, 1st index=start
        activity.push_back({end[i],start[i]});
    }
    sort(activity.begin(),activity.end());
    //limit is end time of an activity
    int limit=activity[0].first,count=1;
    for(int i=1;i<n;i++)
    {
        //if start time of next activity is more than end time of prev activity then only we can do that
        if(activity[i].second>limit)
        {
            limit=activity[i].first;
            count++;
        }
    }
    return count;
}

int main()
{
	vector<int>start={1,3,0,5,8,5};
	vector<int>end={2,4,6,7,9,9};
	int n=start.size();
	int ans=maxmeetings(start,end,n);
	cout<<"Number Of Maximum Activities That Can Be Performed:"<<ans<<endl;
}
