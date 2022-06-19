/*
We have to find triplets whose sum is equal to 0

*/
class Solution {
public:
    //Brute Force - O(n^3)
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n=nums.size();
        if(n<3)
        {
            return {};
        }
        set<vector<int>>st;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    if(nums[i]+nums[j]+nums[k]==0)
                    {
                        st.insert({nums[i],nums[j],nums[k]});
                    }
                }
            }
        }
        vector<vector<int>>v;
        for(auto it=st.begin();it!=st.end();it++)
        {
            v.push_back(*it);
        }
        return v;
    }
    
    //
    
};
