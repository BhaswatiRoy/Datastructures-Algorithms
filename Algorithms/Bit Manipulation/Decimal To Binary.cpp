#include<bits/stdc++.h>
using namespace std;

/*
suppose we have decimal 1011 
2*0 + 1 = 1
2*1 + 0 = 2
2*2 + 1 = 5
2*5 + 1 = 11
thus binary form of 1011 is 5
*/

int getdecimalvalue(vector<int>v) 
{
    int ans=0;
    for(int i=0;i<v.size();i++)
    {
        ans=(ans*2)+v[i];
    }
    return ans;
}

int main()
{
	vector<int>v={1,0,1,1,0};
	int ans=getdecimalvalue(v);
}
