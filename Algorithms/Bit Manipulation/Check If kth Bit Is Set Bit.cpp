#include<bits/stdc++.h>
using namespace std;

/*
Bit Masking -> If n is actual number and mask=1 then we do left shift in mask by k times (mask=mask<<1)
if after this n AND mask!=0 then the kth bit is a set bit
*/

int main()
{
	int n,k;
	cin>>n>>k;
	//mask in Bit Masking
	int mask=1;
	
	//the for loop can be replaced by -> mask<<=k
	for(int i=0;i<k;i++)
	{
		//left shift by 1 bit done k times
		mask<<=1;
	}
	
	if((n & mask)!=0)
	{
		cout<<"Yes Set Bit"<<endl;
	}
	else
	{
		cout<<"Not Set Bit"<<endl; 
	}
}
