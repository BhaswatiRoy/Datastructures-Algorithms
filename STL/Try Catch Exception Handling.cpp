#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string try_catch(int n)
{
	if (n==0)
	{
		throw invalid_argument("0 not acceptable");
	}
	else if (n==1)
	{
		throw invalid_argument("1 not acceptable");
	}
	else
	{
		cout<<"Acceptable"<<endl;
	}
}

int main()
{
	int n;
	cin>>n;
	try
	{
		string d=try_catch(n);
	}
	catch (invalid_argument(e))
	{
		cout<<e.what()<<endl;
	}
	return 0;
}
