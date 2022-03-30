#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() 
{
	vector<int>v={1,2,3,4,5};
	int m;
	cin>>m;
	auto it=lower_bound(v.begin(),v.end(),m);
	//subtracting the address of 1st position of vector gives the index position of the element
	if (m!=*it)
		{
			cout<<"Not Present"<<endl;
		}
		else
		{
			cout<<"Yes Present"<<endl;
		}
		
	//returns index of end position if element is absent
	cout<<(it-v.begin())<<endl;
	
    return 0;
}
