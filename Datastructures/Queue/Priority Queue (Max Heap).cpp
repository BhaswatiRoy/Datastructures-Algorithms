#include <bits/stdc++.h>
using namespace std;

int main() 
{
	//Max Heap in STL
	priority_queue<int>pqmax;
	pqmax.push(2);
	pqmax.push(3);
	pqmax.push(1);
	cout<<"Max Heap:"<<endl;
	//max heap keeps highest/maximum element on top/front
	cout<<"Top Element:"<<pqmax.top()<<endl;
	//pop operation of queue happens from top/front
	pqmax.pop();
	cout<<"After Popping Top Element:"<<pqmax.top()<<endl;
	
	cout<<endl;
}
