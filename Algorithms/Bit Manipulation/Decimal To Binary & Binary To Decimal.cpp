#include<bits/stdc++.h>
using namespace std;

/*
Converting a decimal number to binary format is done in the same way as we do in maths
Again for converting the binary format to decimal we need to do the reverse way 
*/

int main()
{
	int num;
	cin>>num;
	vector<int>binary;
	//convert to binary format and push it to a vector
	cout<<"Binary Form is:";
    while(num!=0)
    {
        binary.push_back(num%2);
        cout<<(num%2)<<" ";
        num=num/2;
    }
    cout<<endl;
    //reverse the order to get actual binary format
    reverse(binary.begin(),binary.end());
    long long t=1;
    for(int i=binary.size()-1;i>=0;i--)
    {
    	num=num+binary[i]*t;
    	t*=2;
	}
	cout<<"Decimal Form is:"<<num<<endl;
}

