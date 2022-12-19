#include <bits/stdc++.h>
using namespace std;

void print(set<int>&st)
{
	for(auto x:st)
	{
		cout<<x<<" ";
	}
	cout<<endl;
}

//comparator function to sort in descending order
bool cmp(pair<int,int>a, pair<int,int>b)
{
	if(a>b)
	{
		return true;
	}
	return false;
}

int main()
{
	//sets internally do sorting 
	//by comparing elements while insertion
	//so we need to use decltype for aesc/desc sorting
	set<int,decltype(cmp)*>st(cmp);
	st.insert(11);
	st.insert(2);
	st.insert(5);
	st.insert(4);
	print(st);
}
