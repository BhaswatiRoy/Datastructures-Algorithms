#include<bits/stdc++.h>
using namespace std;

int main()
{
	//A=2, B=22, C=222; D=3, E=33, F=333, G=4, H=44, I=444, J=5, K=55, L=555, 
	//M=6, N=66, O=666, P=7, Q=77, R=777, S=7777, T=8, U=88, V=888, W=9, X=99, Y=999, Z=9999
	vector<string>v={"2","22","222","3","33","333","4","44","444","5","55","555","6","66","666","7","77","777","7777","8","88","888","9","99","999","9999"};
	string str="BHASWATI",ans="";
	for(int i=0;i<str.length();i++)
	{
		if(str[i]==' ')
		{
			ans+='0';
		}
		else
		{
			//subtracting ASCII value of A to obtain position of that character in v vector
			int idx=str[i]-'A';
			ans+=v[idx];
		}
	}
	cout<<ans<<endl;
}
