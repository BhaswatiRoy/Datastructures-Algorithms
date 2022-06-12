#include<bits/stdc++.h>
using namespace std;

vector<long long> nextgreaterelement(vector<long long> arr, int n)
{
    vector<long long>v(n,0);
    stack<long long>st;
    st.push(-1);
    //iterate from back
    for(int i=n-1;i>=0;i--)
    {
	//if top element is more than current element then that is the next greater element    
        if(st.top()>arr[i])
        {
            v[i]=st.top();
            st.push(arr[i]);
        }
	//otherwise if top element is less than current element    
        else
        {
	    //iterate and remove elements of stack until we get a greater element or untill stack is empty	
            while(!st.empty())
            {
                if(st.top()>arr[i])
                {
                    v[i]=st.top();
                    st.push(arr[i]);
                    break;
                }
                else
                {
                    st.pop();
                }
            }
            //if stack is empty then next greater element is marked as -1
            if(st.empty())
            {
                v[i]=-1;
                st.push(arr[i]);
            }
        }
    }
    return v;
}

int main()
{
	vector<long long>arr={6,8,0,1,3};
	int n=arr.size();
	vector<long long>v=nextgreaterelement(arr,n);
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
