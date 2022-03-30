#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template <typename T>
class AddElements
{
	T a;
	public:
		//constructor to declare a new object that brings value from private section of class
		AddElements(T x)
		{
			a=x;
		}
		T add(T y)
		{
			return a+y;
		}
		T concatenate(T z)
		{
			return a+z;
		}
};

int main()
{
  int n,i;
  cin >> n;
  for(i=0;i<n;i++) 
  {
    string type;
    cin >> type;
    if(type=="float") 
	{
        double element1,element2;
        cin >> element1 >> element2;
        //myfloat=object
        AddElements<double> myfloat (element1);
        cout << myfloat.add(element2) << endl;
    }
    else if(type == "int") 
	{
        int element1, element2;
        cin >> element1 >> element2;
        //myint=object
        AddElements<int> myint (element1);
        cout << myint.add(element2) << endl;
    }
    else if(type == "string") 
	{
        string element1, element2;
        cin >> element1 >> element2;
        //mystring=object
        AddElements<string> mystring (element1);
        cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}
