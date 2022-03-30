#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() 
{
	vector<int>v={1,2,3,4,5};
	auto it=upper_bound(v.begin(),v.end(),3);
	//subtracting the address of 1st position of vector gives the index position of the element
	
	if (m!=*it)
		{
			cout<<"Not Present"<<endl;
		}
		else
		{
			cout<<"Yes Present"<<endl;
		}
	
	cout<<(it-v.begin())<<endl;
	
    return 0;
}
