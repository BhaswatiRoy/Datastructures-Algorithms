#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Since the rows are sorted so all 0 will come before and all 1s will come after it
So after the pos of 1st 1 all pos after that contains 1 
So if we get the lowest column index then that contains highest number of 1s
TC->nlogm {n for traversing all rows fully and logm for traversing columns partially
*/

int rowwithmaxones(vector<vector<int>>&matrix, int n, int m) 
{
	int pos=INT_MAX,idx=-1;
	//the flag will determine if we even have any 1s in our matrix
	bool flag=false;
	for(int i=0;i<n;i++)
	{
	    int j;
	    for(j=0;j<m;j++)
	    {
	        //if we are getting 1 at any j then after that all are 1
	        if(matrix[i][j]==1)
	        {
	        	//flag value is set to T if we get any 1s 
	            flag=true;
	            break;
	        }
	    }
	    //compare if the j is lesser than min j 
	    //lower value of j from which 1 starts means more no of 1s
	    if(j<pos)
	    {
	        pos=j;
	        idx=i;
	    }
	}
	//if we have any 1s in matrix i.e flag value is T then only we will return index
	if(flag==true)
	{
	    return idx;
	}
	//otherwise return -1 if there are no 1s in entire matrix
	return -1;
}

int main()
{
	vector<vector<int>>matrix={{0, 1, 1, 1},
                               {0, 0, 1, 1},
                               {1, 1, 1, 1},
                               {0, 0, 0, 0}};
    cout<<"Row Index With Maximum Number Of 1s:";
    int ans=rowwithmaxones(matrix,4,4);
    cout<<ans;
}
