#include<bits/stdc++.h>
using namespace std;

/*
Min Flips Needed To Make String Binary ALternate
we can make a string 0011 as binary alternate in 2 ways -
1. 0101(1 in odd index & 0 in even index)
2. 1010(1 in even index & 0 in odd index)
so in both ways if some condition is not fulfilled then we need a flip
We will keep counting for both ways and in end return the minimum count
*/

int minflips (string S)
{
    //count1 for 1st way & count2 for 2nd way
    int count1=0,count2=0;
    for(int i=0;i<S.length();i++)
    {
        //even index should contain 1 for flip in 1st case
        if(i%2==0 && S[i]=='1')
        {
            count1++;
        }
        //even index should contain 0 for flip in 2nd case
        if(i%2==0 && S[i]=='0')
        {
            count2++;
        }
        //odd index should contain 1 for flip in 2nd case
        if(i%2!=0 && S[i]=='1')
        {
            count2++;
        }
        if(i%2!=0 && S[i]=='0')
        {
            count1++;
        }
    }
    return min(count1,count2);
}

int main()
{
	string S="0001010111";
	int ans=minflips(S);
	cout<<"Minimum Number Of Flips Needed:"<<ans<<endl;
}
