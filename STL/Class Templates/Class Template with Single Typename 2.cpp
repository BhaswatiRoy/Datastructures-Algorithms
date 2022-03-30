#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template <typename T>

class Weight
{
	private:
		T kg;
	public:
		void SetData(T x)
		{
			kg=x;
		}
		T GetData()
		{
			return kg;
		}
};

int main()
{
	Weight <int>w1;
	w1.SetData(5);
	cout<<"Value of 1st Weight:"<<w1.GetData()<<endl;
	Weight <double>w2;
	w2.SetData(5.6868);
	cout<<"Value of 2nd Weight:"<<w2.GetData()<<endl;
	return 0;
}
