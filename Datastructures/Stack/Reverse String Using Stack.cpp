#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void reverse(string &s)
{
	stack<char>st;
	for(int i=0;i<s.length();i++)
	{
		st.push(s[i]);
	}
	for(int j=0;j<s.length();j++)
	{
		//update elements in string as top element of stack
		s[j]=st.top();
		//remove one element from top
		st.pop();
	}
}

int main()
{
	string s;
	cout<<"Enter a string:";
	cin>>s;
	reverse(s);
	cout<<"Reversed String is:"<<s;
}
