#include<iostream>
using namespace std;

#define PI (3.414)

#define Square(a) a*a

#define add(c,d) c+d

int main()
{
	int n,p,q;
	cout<<PI<<endl;
	cin>>n;
	cout<<Square(n)<<endl;
	cin>>p>>q;
	cout<<add(p,q)<<endl;
	return 0;
}

