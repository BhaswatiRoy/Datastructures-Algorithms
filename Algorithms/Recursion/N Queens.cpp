#include <bits/stdc++.h>
using namespace std;

/*
N Queen - Having n x n chessboard and n queens to place
          We have to place queens in such a way that the queens don't attack eachother

TC - O(n^2), SC - O(n^2)
*/

bool issafe(int row, int col, vector<string>board, int n)
{
    //checking for queen in upper diagonal
    //if queen is found we return F as new queen can't be placed
    int duprow=row;
    int dupcol=col;
    while(row>=0 && col>=0)
    {
        if(board[row][col]=='Q')
        {
            return false;
        }
        //row & col both decreases
        row--;
        col--;
    }
    //checking for queen in same line
    //if queen is found we return F as new queen can't be placed
    col=dupcol;
    row=duprow;
    while(col>=0)
    {
        if(board[row][col]=='Q')
        {
            return false;
        }
        //row remains constant and col decreases
        col--;
    }
    //checking for queen in lower diagronal
    //if queen is found we return F as new queen can't be placed
    row=duprow;
    col=dupcol;
    while(row<n && col>=0)
    {
        if(board[row][col]=='Q')
        {
            return false;
        }
        //row increases but col decreases
        row++;
        col--;
    }
    return true;
}

void solve(int col,vector<string>&board, vector<vector<string>>&ans, int n)
{
    if(col==n)
    {
        ans.push_back(board);
        return;
    }
    //trying to place queen in a position if it is safe
    for(int row=0;row<n;row++)
    {
        if(issafe(row,col,board,n)==true)
        {
            board[row][col]='Q';
            solve(col+1,board,ans,n);
            board[row][col]='.';
        }
    }
}

vector<vector<string>>nqueens(int n) 
{
    vector<vector<string>>ans;
    vector<string>board(n);
    string s(n,'.');
    for(int i=0;i<n;i++)
    {
        board[i]=s;
    }
    solve(0,board,ans,n);
    return ans;
}

int main()
{
	int n=4;
	vector<vector<string>>finalans=nqueens(n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<finalans[i][j]<<endl;
		}
		cout<<endl<<endl;
	}
	cout<<endl;
}
