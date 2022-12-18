#include <bits/stdc++.h>
using namespace std;

void print(vector<int>&v)
{
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

//comparator function to sort in descending order
bool cmp(int a, int b)
{
	if(a>b)
	{
		return true;
	}
	return false;
}
 
int main()
{
	vector<int>v={1,4,3,7,19};
	print(v);
	sort(v.begin(),v.end());
	print(v);
	sort(v.begin(),v.end(),cmp);
	print(v);
}
