#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Matrix Rotation BY 90 Degrees - Tranpose + Reverse each row/take mirror about vertical line
*/

void rotate(vector<vector<int>>& matrix) 
{
    int n=matrix.size();
    //do transpose of the matrix
    for(int i=0;i<n;i++)
    {
        //loop upto i because other elements will automatically get swapped
        for(int j=0;j<i;j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    //then reverse each row i.e take mirror image about vertical line
    for(int i=0;i<n;i++)
    {
        reverse(matrix[i].begin(),matrix[i].end());
    }
}

int main()
{
	vector<vector<int>>matrix={{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15,16}};
    rotate(matrix);
    cout<<"Matrix After Rotation By 90 Degrees:"<<endl;
    for(int p=0;p<4;p++)
    {
    	for(int q=0;q<4;q++)
    	{
    		cout<<matrix[p][q]<<" ";
		}
		cout<<endl;
	}
}
