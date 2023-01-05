#include<bits/stdc++.h>
using namespace std;

/*
v = 0 0 0 0 0, v = 0 0 0 0 0 0 (extra 0 for r+1 on last index)
adding k from l to r index in vector v
queries => l=1,r=4,k=2 => v[1]+=k, v[5]-=k
           pf = 0 2 2 2 2 0 
		   (query is performed acc to prefix sum array) 
*/
 
int main()
{
	vector<int>v={0,0,0,0,0};
	//this extra 0 is added for doing r+1 at last index
	v.push_back(0);
	int q,n=v.size();
	cin>>q;
	while(q--)
	{
		int l,r,k;
		cin>>l>>r>>k;
		v[l]+=k;
		v[r+1]-=k;
	}
	vector<int>pf(n+1,0);
	pf[0]=v[0];
	for(int i=1;i<=n;i++)
	{
		pf[i]=pf[i-1]+v[i];
	}
	for(int k=0;k<n;k++)
	{
		cout<<pf[k]<<" ";
	}
	cout<<endl;
}
