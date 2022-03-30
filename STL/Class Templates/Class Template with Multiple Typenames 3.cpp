#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template <typename T,typename U,typename V,typename W>
class Student
{
	T age1;
	U fname1;
	V lname1;
	W stand1;
	public:
		setvalue(T age,U fname,V lname,W stand)
		{
			age=age1;
			fname=fname1;
			lname=lname1;
			stand=stand1;
		}
		T getage(T age)
		{
			return age;
		}
		U getfname(U fname)
		{
			return fname;
		}
		V getlname(V lname)
		{
			return lname;
		}
		W getstand(W stand)
		{
			return stand;
		}
};

int main()
{
	int a;
	string fn,ln;
	int std;
	cin>>a>>fn>>ln>>std;
	Student<int,string,string,int>s;
	s.setvalue(a,fn,ln,std);
	cout<<s.getage(a)<<endl;
	cout<<s.getlname(ln)<<", "<<s.getfname(fn)<<endl;
	cout<<s.getstand(std);
	cout<<endl<<s.getage(a)<<","<<s.getfname(fn)<<","<<s.getlname(ln)<<","<<s.getstand(std);
	return 0;
}
