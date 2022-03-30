#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//general syntax to implement templates
template <typename T,typename V>

//class creation with templates
class Pair
{
	T x;
	V y;
	public:
		//constructor
		Pair(T a, V b)
		{
			x=a;
			y=b;
		}
		T getfirst()
		{
			return x;
		}
		T getsecond()
		{
			return y;
		}
};

int main() 
{
	Pair<int,float>p3(2,3.5);
	cout<<p3.getfirst()<<" "<<p3.getsecond()<<endl;
	
    return 0;
}
