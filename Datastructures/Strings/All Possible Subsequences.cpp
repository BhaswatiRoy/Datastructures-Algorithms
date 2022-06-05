#include<bits/stdc++.h>
using namespace std;

/*
All Possible Subsequences ->
We have two choices for each character either to pick it or not pick it
TC is (2^n)
*/


void printallsubsequences(string str,int idx,int n, string finalstr)
{
	//base case is hit when we have idx as equal or more than n
	if(idx>=n)
	{
		cout<<finalstr<<endl;
		return;
	}
	//recursive function call for not picking the character
	printallsubsequences(str,idx+1,n,finalstr);
	
	//adding the character
	finalstr+=str[idx];
	//recursive function call for picking the character
	printallsubsequences(str,idx+1,n,finalstr);
}

int main()
{
	string str="abc",finalstr="";
	printallsubsequences(str,0,str.length(),finalstr);
}
