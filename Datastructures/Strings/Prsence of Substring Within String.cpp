#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str="apna collegena";
	string substr="na";
	int n=str.size(),m=substr.size();
	for(int i=0;i<n;i++)
	{
		//the 1st parameter is starting index and 2nd parameter is how far from starting index we will check
		if(str.substr(i,m)==substr)
		{
			cout<<"Substring present at "<<i<<" index"<<endl;
		}
	}
}

