#include<bits/stdc++.h>
using namespace std;

/*
Given the no of days to survive(S), no of food units that can be bought per day(N), no of food units needed per day(M) 
we need to find that if a person can survive on an island which has only 1 shop that remains closed only on sundays
*/

//S=no of days to survive, N=food units that can be bought per day, M=food units needed per day
int mindays(int S, int N, int M)
{
	//if food units bough per day is less than food units needed per day then can't survive
    if(N<M)
    {
        return -1;
    }
    //we can't buy food on sundays but can buy on rest days
    //there are S/7 sundays and rest normal days
    int foodreq=S*M,nobuy=S/7,yesbuy=S-nobuy;
    //no of days needed to buy req food if we can buy N units food per day
    int days=foodreq/N;
    if(foodreq%N!=0)
    {
        //if foodreq is perfectly divisible by N then the day count is same
        //if not then there are extra days remaining
        days++;
    }
    if(days<=yesbuy)
    {
        return days;
    }
    return -1;
}

int main()
{
	int ans=mindays(10,16,2);
	if(ans==-1)
	{
		cout<<"Can't Survive!"<<endl;
	}
	else
	{
		cout<<"Can Survive For "<<ans<< " Days"<<endl;
	}
}
