#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Count Squares-
output the number of integers less than N which are perfect squares
*/

int countsquares(int N) 
{
    //sq root is saved in int format so sqrt(20)=4.5 but will be stored as 4
    int a=sqrt(N);
    //if sq of a is equal to N then a-1 perfect squares are present
    if(a*a==N)
    {
        return a-1;
    }
    else
    {
        return a;
    }
}

int main()
{
	int n=9;
	int count=countsquares(n);
	cout<<"No Of Square Numbers Less Than "<<n<<": "<<count;
}
