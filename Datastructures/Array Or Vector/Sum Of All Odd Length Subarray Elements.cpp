#include<bits/stdc++.h>
using namespace std;

/*All odd length subarrays are-
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
total sum -> 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
*/

int main()
{
	vector<int>v={1,4,2,5,3};
	int sum=0;
    for(int i=0;i<v.size();i++)
    {
        int tempsum=0;
        for(int j=i;j<v.size();j++)
        {
            tempsum+=v[j];
            //odd length subarray will always have index diff of 1st & last index as even
            if((j-i)%2==0)
            {
                sum+=tempsum;
            }
        }
    }
    cout<<"Total sum of all odd length subarrays are:"<<sum<<endl;
}

