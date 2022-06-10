#include<bits/stdc++.h>
using namespace std;

int lengthoflongestsubstring(string s) 
{
    unordered_map<char,int>mp;
    int i=0,j=0,n=s.length(),maxlen=0;
    while(j<n)
    {
        //store frequency of current element of string in map
        mp[s[j]]++;
        //if the character is not occuring only once then reduce the frequency and increment start pointer of window
        while(mp[s[j]]!=1)
        {
            mp[s[i]]--;
            i++;
        }
        //compare current window size & max window size
        maxlen=max(maxlen,j-i+1);
        //increment end pointer of window
        j++;
    }
    return maxlen;      
}

int main()
{
	string s="pwwkew";
	int len=lengthoflongestsubstring(s);
	cout<<"Length of Longest Substring Without Repeating Characters:"<<len<<endl;
}
