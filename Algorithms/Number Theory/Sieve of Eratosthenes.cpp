#include<bits/stdc++.h>
using namespace std;

/*
Whenever we come across a number 
we mark all it's multiples as non prime
Eg - reaching 3 we mark 6,9,12,15.... as non primes(false)

TC - n*log(logn)
*/
 
int main()
{
    vector<bool>primes(n+1,true);
    primes[0]=primes[1]=false;
    for(int i=2;i*i<=n;i++)
    {
    	if(primes[i]==true)
    	{
    		for(int j=i*i;j<=n;j+=i)
    		{
    			primes[j]=false;
			}
		}
	}
}
