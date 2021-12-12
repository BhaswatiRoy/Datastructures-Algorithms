#include<iostream>
#include<bits/stdc++.h>
using namespace std;

stack<char>st;

void check(string t)
{
	for(int i=0;i<t.length();i++)
	{
		//if open bracket if found then push to stack
		if(t[i]=='(' || t[i]=='{' || t[i]=='[')
		{
			st.push(t[i]);
		}
		//if closing bracket is found check further
		else if(t[i]==')' || t[i]=='}' || t[i]==']')
		{
			if(st.empty()==true)
			{
				cout<<"Not Balanced!"<<endl;
				return;
			}
			//incase the top element of stack pairs up with 
			else if(t[i]==')' && st.top()=='(')
			{
				st.pop();
			}
			else if(t[i]=='}' && st.top()=='{')
			{
				st.pop();
			}
			else if(t[i]==']' && st.top()=='[')
			{
				st.pop();
			}
		}
	}
	if(st.empty()==true)
	{
		cout<<"Balanced!"<<endl;
	}
	else
	{
		cout<<"Not Balanced!"<<endl;
	}
}

int main()
{
	string s="{[(]}";
	check(s);
}
