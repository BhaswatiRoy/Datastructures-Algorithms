#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() 
{
	set<int>s;
	s.insert(3);
	s.insert(4);
	s.insert(5);
	//duplicate elements get removed
	s.insert(5);
	
	sort(s.begin(),s.end());
	
	//erasing one element
	s.erase(4);
	
	cout<<s.size()<<endl;
	
	int m;
	cin>>m;
	auto it=s.find(m);
	if (it!=s.end())
	{
		cout<<"Present"<<endl;
	}
	else
	{
		cout<<"Absent"<<endl;
	}
	
	cout<<s.count(5)<<endl;
	
	s.clear();
	if(s.empty())
	{
		cout<<"Empty"<<endl;
	}
	else
	{
		cout<<"Not Empty"<<endl;
	}
	
    return 0;
}
