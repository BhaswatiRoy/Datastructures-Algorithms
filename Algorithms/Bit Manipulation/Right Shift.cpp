#include<bits/stdc++.h>
using namespace std;

//n>>x = n/(2^x)

int main()
{
	int n,x;
	cin>>n>>x;
	int leftshift=(n>>x);
	cout<<"Left Shift Operation "<<n<<" >> "<<x<<" = "<<leftshift<<endl;
}
