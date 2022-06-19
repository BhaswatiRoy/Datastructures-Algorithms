#include<bits/stdc++.h>
using namespace std;

vector<int> stackrevbrute(stack<int>&st)
{
	vector<int>v;
	while(!st.empty())
	{
		v.push_back(st.top());
		st.pop();
	}
	return v;
}

//now we will call this functiont o insert elments in a insert bottom manner
//suppose we have inserted 3 previously then we will pull out 3 and insert 2 then insert 3
//again when we have to insert 1 then we will pull out 3 then 2 and insert 1 then insert 2 then 2
//while pulling out the elements are stored in another call/recursion stack
void insertatbottom(stack<int>&st,int elem)
{
	if(st.empty())
	{
		st.push(elem);
		return;
	}
	int topelem=st.top();
	st.pop();
	insertatbottom(st,topelem);
	
	st.push(topelem);
}

//store elements recursively in call/recursion stack
//recursively call the function for rest elements other than top element
//suppose elements - 1,2,3 will be stored as 3,2,1 in call/recursion stack
void stackrevrecursion(stack<int>&st)
{
	//when stack is empty we will stop
	if(st.empty())
	{
		return;
	}
	int elem=st.top();
	st.pop();
	
	stackrevrecursion(st);
	
	insertatbottom(st,elem);
}

int main()
{
	stack<int>st1;
	vector<int>v;
	st1.push(1);
	st1.push(2);
	st1.push(3);
	st1.push(4);
	st1.push(5);
	v=stackrevbrute(st1);
	cout<<"Stack After Reversal By Brute Force Is:";
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	
	stack<int>st2;
	st2.push(1);
	st2.push(2);
	st2.push(3);
	st2.push(4);
	st2.push(5);
	cout<<"Stack After Reversal By Recursion Is:";
	while(!st2.empty())
	{
		cout<<st2.top()<<" ";
		st2.pop();
	}
	cout<<endl;
}
