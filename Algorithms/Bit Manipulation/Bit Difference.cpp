#include<bits/stdc++.h>
using namespace std;

/*
a^b = xor gives 1 for the values which are different like 1^0=1 & 0^1=1
so we need to count how many set bits are in a^b those many bits are different and need flipping
TC is O(n) for n bits of a number x
*/

int main()
{
	int a=10,b=20;
	long long n=a^b;
    cout<<"Number Of Bits To Flip:"<< __builtin_popcount(n)<<endl;
}
