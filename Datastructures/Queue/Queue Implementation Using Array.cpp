#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define size 100

int arr[size];

//declaring empty queue with front & rear values as -1 denoting empty queue
int front=-1;
int rear=-1;

void enqueue(int x)
{
	//if queue is full then we can not add more elements
	if(rear==(size-1))
	{
		cout<<"Queue is full!"<<endl;
		return;
	}
	//if queue is empty then we will make both index as 0
	else if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
	}
	else
	{
		rear++;
	}
	//enqueue always occurs from rear end
	arr[rear]=x;
}

void dequeue()
{
	//checking if queue is empty
	if(front==-1 && rear==-1)
	{
		cout<<"Queue is empty!"<<endl;
		return;
	}
	else if(front==rear)
	{
		//if there is only 1 element in queue then on removal queue becomes empty
		front=-1;
		rear=-1;
	}
	else
	{
		//increment front by 1
		front++;
	}
}

void print()
{
	cout<<"Queue is:";
	for(int i=0;i<=rear;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	print();
	dequeue();
	cout<<"After Dequeue:";
	print();
	enqueue(6);
	cout<<"After Enqueue:";
	print();
}
