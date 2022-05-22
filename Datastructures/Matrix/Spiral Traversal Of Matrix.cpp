#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> spirallytraverse(vector<vector<int>>matrix, int r, int c) 
{
    //the 4 edge corners of the matrix are denotes by top,down,left,right
    //suppose in the given case top=1,down=13,left=13,right=16
    int top=0,down=r-1,left=0,right=c-1;
    //dir=0(right), dir=1(down), dir=2(left), dir=3(top)
    int dir=0;
    vector<int>ans;
    //horizontal movement->left & right, vertical->top & down
    while(top<=down && left<=right)
    {
    	//moving left to right
        if(dir==0)
        {
            for(int i=left;i<=right;i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++;
        }
        //moving top to down
        else if(dir==1)
        {
            for(int j=top;j<=down;j++)
            {
                ans.push_back(matrix[j][right]);
            }
            right--;
        }
        //moving right to left
        else if(dir==2)
        {
            for(int k=right;k>=left;k--)
            {
                ans.push_back(matrix[down][k]);
            }
            down--;
        }
        //moving down to top
        else if(dir==3)
        {
            for(int l=down;l>=top;l--)
            {
                ans.push_back(matrix[l][left]);
            }
            left++;
        }
        //this is done to increment dir in such a way that it becomes 0,1,2,3 everytime so the 4 conditions are followed one by one
        dir=(dir+1)%4;
    }
    return ans;
}

int main()
{
	vector<vector<int>>matrix={{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15,16}};
    vector<int>ans=spirallytraverse(matrix,4,4);
    cout<<"Spiral Traversal Of Matrix:";
    for(int i=0;i<ans.size();i++)
    {
    	cout<<ans[i]<<" ";
	}
	cout<<endl;
}
