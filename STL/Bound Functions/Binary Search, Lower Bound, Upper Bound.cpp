#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int>v={1,3,5,6,7,8,2,2,5};
	//prints bool value if element if present or not
	bool present=binary_search(v.begin(),v.end(),11);
	cout<<present<<endl;
	
	//prints iterator greater than or equal to target
	auto it1=lower_bound(v.begin(),v.end(),6);
	cout<<it1-v.begin()<<endl;
	
	//prints iterator greater to target
	auto it2=upper_bound(v.begin(),v.end(),6);
	cout<<it2-v.begin()<<endl;
}
