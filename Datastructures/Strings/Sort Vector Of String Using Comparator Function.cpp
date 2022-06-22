#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool comparator(string &a, string &b)
{
    if(a.size()!=b.size())
    {
        //suppose 10 & 7 is to be compared then 7 should be smaller 
        //if we don't mention this then 10 will be declared smaller as 1st digit is 1
        return a.size()<b.size();
    }
    return a<b;
}

void sortstringvector(vector<string>& nums) 
{
    sort(nums.begin(),nums.end(),comparator);
}

int main()
{
	vector<string>nums={"623986800","3","887298","695","794","6888794705","269409","59930972",
	"723091307","726368","8028385786","378585"};
	sortstringvector(nums);
	cout<<"Sorted Format is:";
	for(int i=0;i<nums.size();i++)
	{
		cout<<nums[i]<<" ";
	}
	cout<<endl;
}
