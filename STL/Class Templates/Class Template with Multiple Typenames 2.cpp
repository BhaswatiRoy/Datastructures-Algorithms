#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template <typename T, typename V>
class Weight
{
	private:
		T kg;
		V gm;
	public:
		void SetData(T x, V y)
		{
			//assigning value of private parts of class to public
			x=kg;
			y=gm;
		}
		T GetkgData()
		{
			return kg;
		}
		V GetgmData()
		{
			return gm;
		}
};

int main()
{
	Weight<int,double>w;
	w.SetData(5,5.6868);
	cout<<"Weights (kg) are:"<<w.GetkgData()<<endl;
	cout<<"Weights (gm) are:"<<w.GetgmData()<<endl;
	return 0;
	
}
