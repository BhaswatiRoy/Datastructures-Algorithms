#include<bits/stdc++.h>
using namespace std;

/*
We initially set all the days as -1 indicating no job performed in the job counting vector.
Then sort the jobs in descending order according to profit given. 
Then we try to finish a job before or on the day of deadline and mark the job as done in job counting vector.
This way we keep doing untill whole of job counting vector is full and no more jobs can be done.
We try to do a job as late as possible so that we can make space for doing other jobs.
TC -> nlogn + n*m {we are traversing n jobs and try to search m job positions before it to check}
*/

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

static bool comparator(Job a, Job b)
{
    return (a.profit>b.profit);
}
vector<int> JobScheduling(Job arr[], int n) 
{ 
    //the elements of structure are - Job Id(id), Deadline(dead), Profit(profit)
    //so we can accesss respective elements by - .id, .dead, .profit
    vector<int>done(n,-1);
    sort(arr,arr+n,comparator);
    int day=0,profit=0;
    for(int i=0;i<n;i++)
    {
        //it might happen that deadline is >=n and in that case we have to take n
        for(int j=min(n,arr[i].dead-1);j>=0;j--)
        {
            if(done[j]==-1)
            {
                day+=1;
                profit+=arr[i].profit;
                done[j]=1;
                break;
            }
        }
    }
    return {day,profit};
}

int main()
{
    int n;
    cout<<"Enter Number Of Jobs:";
    cin>>n;
    Job arr[n];
    cout<<"Enter Job Details(Id, Deadline, Profit):"<<endl;
    for(int k=0;k<n;k++)
    {
    	int x,y,z;
    	cin>>x>>y>>z;
    	arr[k].id=x;
    	arr[k].dead=y;
    	arr[k].profit=z;
	}
	vector<int>ans=JobScheduling(arr,n);
	cout<<"Total Jobs Done:"<<ans[0]<<endl;
	cout<<"Maximum Profit Gained:"<<ans[1]<<endl;
}
