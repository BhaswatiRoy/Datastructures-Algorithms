
//TC = O(n^3logm), SC = O(m) -> m = set size
vector<vector<int>>threesumbrute(vector<int>&nums) 
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

//TC = O(n^2logm), SC = O(m) -> m = set size
vector<vector<int>> threeSum(vector<int>& nums) 
{
        int n=nums.size();
        if(n<3)
        {
            return {};
        }
        sort(nums.begin(),nums.end());
        if(nums[0]>0)
        {
            return {};
        }
        unordered_map<int,int>mp;
        for(int p=0;p<n;p++)
        {
            mp[nums[p]]++;
        }
        set<vector<int>>st;
        //we need a+b+c=0 -> c=-(a+b)
        //once we take a & b into countn we make sure that they are not considered once again when we find c in map
        for(int i=0;i<n-2;i++)
        {
            int a=nums[i];
            //remove a as once a is considered
            mp[a]--;
            for(int j=i+1;j<n-1;j++)
            {
                int b=nums[j];
                //remove b as once b is considered
                mp[b]--;
                int c= -(a+b);
                //check if c is present in the map
                if(mp[c]>0)
                {
                    vector<int>temp={a,b,c};
                    sort(temp.begin(),temp.end());
                    st.insert({temp});
                }
                mp[b]++;
            }
            mp[a]++;
        }
        vector<vector<int>>v;
        for(auto it=st.begin();it!=st.end();it++)
        {
            v.push_back(*it);
        }
        return v;
}

//TC = O(n^2), SC = O(1)
vector<vector<int>> threeSum(vector<int>& nums) 
{
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        //a+b+c=0 -> (b+c)=(-a)
        //move this loop for finding a
        for(int i=0;i<n-2;i++)
        {
            //if a is at 0th index then there is no element before it so need to check duplicates
            //but if a is not at 0th index we need to check duplicates with previous index
            if(i==0 || (i>0 && nums[i]!=nums[i-1]))
            {
                //low will start at next index of i and high from last index
                //sum = -(a) = -(nums[i])
                //low = b, high = c
                int low=i+1,high=n-1,sum=-(nums[i]);
                while(low<high)
                {
                    //if b+c is equal to sum then we can add that into our ans
                    if(nums[low]+nums[high]==sum)
                    {
                        ans.push_back({nums[i],nums[low],nums[high]});
                        //and we can also increment b upto a point where we find different elements to avoid duplicates
                        while(low<high && nums[low]==nums[low+1])
                        {
                            low++;
                        }
                        //and we can also decrement c upto a point where we find different elements to avoid duplicates
                        while(low<high && nums[high]==nums[high-1])
                        {
                            high--;
                        }
                        low++;
                        high--;
                    }
                    //since vector is sorted and b+c is less than sum so we need to increment b
                    else if(nums[low]+nums[high]<sum)
                    {
                        low++;
                    }
                    //since vector is sorted and b+c is more than sum so we need to decrement c
                    else if(nums[low]+nums[high]>sum)
                    {
                        high--;
                    }
                }
            }
        }
        return ans;
}
