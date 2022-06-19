#include<bits/stdc++.h>
using namespace std;

/*
Only functions are implemented not entire code
In one array one stack is in beginning portion of the array and another stack is in ending portion of the array
*/

class twoStacks
{
    int *arr;
    int size;
    int top1, top2;
    
public:
   twoStacks(int n=100){size = n; arr = new int[n]; top1 = -1; top2 = size;}
 
   void push1(int x);
   void push2(int x);
   int pop1();
   int pop2();
};

//tp1 is -1 and tp2 is arr.size() as predefined
//so 1st stack is defined from beginning of array and 2nd stack is defined 

//Function to push an integer into the stack1.
void twoStacks :: push1(int x)
{
    top1++;
    arr[top1]=x;
}

//Function to push an integer into the stack2.
void twoStacks ::push2(int x)
{
    top2--;
    arr[top2]=x;
}

//Function to remove an element from top of the stack1 - front of array
int twoStacks ::pop1()
{
    if(top1==-1)
    {
        return -1;
    }
    else
    {
        return arr[top1--];
    }
}

//Function to remove an element from top of the stack2 - back of array
int twoStacks :: pop2()
{
    if(top2==size)
    {
        return -1;
    }
    else
    {
        return arr[top2++];
    }
}

int main()
{
	
}



