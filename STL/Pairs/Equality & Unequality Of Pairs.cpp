#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() 
{
	//compiler checks the 1st value then 2nd value of both values in a pair
	pair<int,int>p1(2,3);
	pair<int,int>p2=make_pair(2,3);
	
	pair<int,int>p3(5,6);
	pair<int,int>p4=make_pair(7,8);
	
	//if both values of both pairs are equal
	if (p1==p2)
	{
		cout<<"Equal"<<endl;
	}
	else
	{
		cout<<"Unequal"<<endl;
	}
	
	if (p3!=p4)
	{
		cout<<"Unequal"<<endl;
	}
	else
	{
		cout<<"Equal"<<endl;
	}
	
    return 0;
}

