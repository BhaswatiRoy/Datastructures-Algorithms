#include <bits/stdc++.h>
using namespace std;

//calculation of postfix notation- 23*=6
//everyime an operator is found we need to do operation of 2 operands and push to stack

stack<int>st;

void postfixevaluation(string str)
{
	int op1,op2,result;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]>='0' && str[i]<='9')
		{
			//subtracting ascii value to find the numerical value for calculations
			st.push(str[i]-'0');
		}
		else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='^')
		{
			op2=st.top();
			st.pop();
			op1=st.top();
			st.pop();
			if(str[i]=='+')
			{
				st.push(op1+op2);
			}
			else if(str[i]=='-')
			{
				st.push(op1-op2);
			}
			else if(str[i]=='*')
			{
				st.push(op1*op2);
			}
			else if(str[i]=='/')
			{
				st.push(op1/op2);
			}
			else if(str[i]=='^')
			{
				st.push(pow(op1,op2));
			}
		}
	}
	cout<<"Postfix Evaluation is:"<<st.top()<<endl;
}

int main()
{
	string str;
	cout<<"Enter the expression:";
	getline(cin,str);
	postfixevaluation(str);
}

