#include<bits/stdc++.h>
using namespace std;

/*A string 1 is rotation of string 2 if the string 2 is present in the concatenated string of both*/

bool arerotations(string str1,string str2)
{
	if(str1.length()!=str2.length())
	{
		return false;
	}
	string con=str1+str2;
	//npos is a special type of constant indicates nothing is returned by find() function
	return (con.find(str2) != string::npos);
}

int main()
{
	string str1="ABACD",str2="CDABA";
	if(arerotations(str1,str2)==true)
	{
		cout<<"Yes Rotaions Of Each Other!"<<endl;
	}
	else
	{
		cout<<"No Not Rotations Of Eachother!"<<endl;
	}
}
