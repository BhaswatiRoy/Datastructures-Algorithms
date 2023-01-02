#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n+1,vector<int>(m+1,0));
    vector<vector<int>>pf(n+1,vector<int>(m+1,0));
    //using 1 based indexing helps us avoid out of bounds exception
    for(int c=1;c<=n;c++)
    {
    	for(int d=1;d<=m;d++)
    	{
    		cin>>v[c][d];
		}
	}
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++)
    	{
    		//for i=1,j=1 we have 0+0+v[1][1]-0
    		//since initially entire array is filled with 0
    		//and we used 1-based indexing
    		pf[i][j]=pf[i-1][j]+pf[i][j-1]+v[i][j]-pf[i-1][j-1];
		}
	}
	//priting sum from (x1,y1) to (x2,y2) index
	int x1,x2,y1,y2;
	cin>>x1>>y1>>x2>>y2;
	cout<<pf[x2][y2]-pf[x1-1][y2]-pf[x2][y1-1]+pf[x1-1][y1-1]<<endl;
}
