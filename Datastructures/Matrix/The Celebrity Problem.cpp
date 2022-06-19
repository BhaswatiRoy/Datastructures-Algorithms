#include<bits/stdc++.h>
using namespace std;

/*
Celebrity Problem - A person is celebrity if everyone knows him but he doesn't knows anyone
M[i][j]=1 means person i knows person j
M[i][i] will always be 0
*/

//brute force approach - O(n^2)
int celebritybrute(vector<vector<int>>& M, int n) 
{
    //in->no of people knows i, out->no of people whom i knows
    vector<int>in(n,0),out(n,0);
    //now iterating entire matrix we can find this count for every person's in and out
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            //this means i knows j
            if(M[i][j]==1)
            {
                //i knows 1 person
                out[i]++;
                //1 person knows j
                in[j]++;
            }
        }
    }
    for(int k=0;k<n;k++)
    {
        //every person except k himself knows k 
        //also k doesn't knows anyone
        if(in[k]==n-1 && out[k]==0)
        {
            return k;
        }
    }
    return -1;
}

//optimal approach - O(n)
int celebrityoptimal(vector<vector<int>>& M, int n) 
{
    //initially celebrity is assumed to be 0 index person
    int c=0;
    for(int i=0;i<n;i++)
    {
        //if c knows i index person then c can't be celebrity 
        if(M[c][i]==1)
        {
            //thus there are chances that i index person can be celebrity
            c=i;
        }
    }
    //now to make sure that final value of c is actually celebrity or not
    for(int j=0;j<n;j++)
    {
        //i should not be c as we can't compare any person to itself
        //now if there is a case that c knows someone or someone doesn't knows c then c is not celebrity
        if(j!=c && (M[c][j]==1 || M[j][c]==0))
        {
            return -1;
        }
    }
    return c;
}

int main()
{
	vector<vector<int>>M={{0,1,0},
                          {0,0,0}, 
                          {0,1,0}};
    int n=M.size();
    int ans1=celebritybrute(M,n);
    cout<<"Celebrity By Brute Force is:"<<ans1<<endl;
    
    int ans2=celebrityoptimal(M,n);
    cout<<"Celebrity By Brute Force is:"<<ans2<<endl;
}
