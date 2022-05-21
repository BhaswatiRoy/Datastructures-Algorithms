#include<bits/stdc++.h>
using namespace std;

//linear search -> TC = n^2
bool searchmatrixlinear(vector<vector<int>>& matrix, int target) 
{
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[i].size();j++)
        {
            if(matrix[i][j]==target)
            {
                return true;
            }
        }
    }
    return false;
}

//binary search -> TC= nlogm
bool searchmatrixbinary(vector<vector<int>>& matrix, int target) 
{
    //n = column size , m = row size
    int n=matrix.size();
    int m=matrix[0].size();
    //matrix has 0 rows or 0 colums
    if(n==0 || m==0)
    {
        return false;
    }
    int left=0,right=n*m-1;
    //arr[mid] = matrix[mid/y][mid%y] 
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if(matrix[mid/m][mid%m]==target)
        {
            return true;
        }
        else if (target<matrix[mid/m][mid%m])
        {
            right=mid-1;
        }
        else if(target>matrix[mid/m][mid%m])
        {
            left=mid+1;
        }
    }
    return false;
}

int main()
{
	vector<vector<int>>matrix={ {1,3,5,7} , {10,11,16,20} , {23,30,34,60} };
	int target=3;
	int anslinear=searchmatrixlinear(matrix,target);
	cout<<"Linear Search"<<endl;
	if(anslinear==true)
	{
		cout<<"Element Present!!"<<endl;
	}
	else
	{
		cout<<"Element Absent!!"<<endl;
	}
	
	cout<<endl;
	
	cout<<"Binary Search"<<endl;
	int ansbinary=searchmatrixbinary(matrix,target);
	if(ansbinary==true)
	{
		cout<<"Element Present!!"<<endl;
	}
	else
	{
		cout<<"Element Absent!!"<<endl;
	}
}
