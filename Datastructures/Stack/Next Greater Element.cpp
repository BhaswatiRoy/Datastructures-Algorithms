#include<bits/stdc++.h>
using namespace std;

vector<long long> nextgreaterelement(vector<long long> arr, int n)
{
    vector<long long>v(n,0);
    stack<long long>st;
    st.push(-1);
    for(int i=n-1;i>=0;i--)
    {
        if(st.top()>arr[i])
        {
            v[i]=st.top();
            st.push(arr[i]);
        }
        else
        {
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
