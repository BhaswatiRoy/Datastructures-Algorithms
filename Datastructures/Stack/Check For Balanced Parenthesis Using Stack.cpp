#include<bits/stdc++.h>
using namespace std;

bool ispar(string x)
{
    stack<char>st;
    for(int i=0;i<x.length();i++)
    {
    	//if opening then put in stack
        if(x[i]=='(' || x[i]=='{' || x[i]=='[')
        {
            st.push(x[i]);
        }
        //if closing then check
        else if(x[i]==')' || x[i]=='}' || x[i]==']')
        {
        	//if stack not empty
            if(!st.empty())
            {
            	//if pais match then remove from stack
                if(st.top()=='(' && x[i]==')')
                {
                    st.pop();
                }
                else if(st.top()=='{' && x[i]=='}')
                {
                    st.pop();
                }
                else if(st.top()=='[' && x[i]==']')
                {
                    st.pop();
                }
                //if pairs don't match then not valid
                else
                {
                    return false;
                }
            }
            //if stack empty then no opening braces is present but closing present so not valid
            else if(st.empty())
            {
                return false;
            }
        }
    }
    //in end if stack is empty mean all pairs matched then valid
    if(st.empty())
    {
        return true;
    }
    return false;
}

int main()
{
	string str="[{()}]";
	bool ans=ispar(str);
	if(ans==true)
	{
		cout<<"Yes Valid !!"<<endl;
	}
	else if(ans==false)
	{
		cout<<"Not Valid !!"<<endl;
	}
}
