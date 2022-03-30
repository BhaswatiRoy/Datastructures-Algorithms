#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//general syntax to implement templates
template <typename T>
//class creation with templates
class Pair
{
	T x;
	T y;
	public:
		//constructor
		Pair(T a, T b)  
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
	//we are accessing getfirst() and getsecond() functions which return values enclosed inside public section of class
    //since the public section of class can access the private section of class and from public section we get indirect access to private section
	Pair<int>p1(3,5);
	cout<<p1.getfirst()<<" "<<p1.getsecond()<<" "<<endl;
	Pair<float>p2(3.5,7.8);
	cout<<p2.getfirst()<<" "<<p2.getsecond()<<" "<<endl;
    return 0;
}
