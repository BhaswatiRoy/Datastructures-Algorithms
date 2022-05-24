#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Toeplitz Matrix - A matrix which has all same elements in 1 diagonal of that matrix 
*/

bool istoeplitzmatrix(vector<vector<int>>& matrix) 
{
    int m=matrix.size(),n=matrix[0].size();
    for(int i=0;i<m-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            //digonal elements are always - (i,j),(i+k,j+k) where k=1,2,3,4......
            if(matrix[i][j]!=matrix[i+1][j+1])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
	vector<vector<int>>matrix={{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15,16}};
    bool ans=istoeplitzmatrix(matrix);
    if(ans==true)
    {
    	cout<<"Yes Toeplitz Matrix!"<<endl;
	}
	else
	{
		cout<<"Not Toeplitz Matrix!"<<endl;
	}
}
