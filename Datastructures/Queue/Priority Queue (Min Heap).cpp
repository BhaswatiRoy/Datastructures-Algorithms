#include <bits/stdc++.h>
using namespace std;

int main() 
{
	//Min Heap in STL
	priority_queue<int,vector<int>,greater<int>>pqmin;
	pqmin.push(5);
	pqmin.push(6);
	pqmin.push(4);
	cout<<"Min Heap:"<<endl;
	cout<<"Top Element:"<<pqmin.top()<<endl;
	//pop operation of queue happens from top/front
	pqmin.pop();
	cout<<"After Popping Top Element:"<<pqmin.top()<<endl;
	
	cout<<endl;
}
