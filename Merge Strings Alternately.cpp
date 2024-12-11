Problem: https://leetcode.com/problems/merge-strings-alternately/description/

/*
Approach:
1. Iterate through both strings using 2 pointers and add characters from both
2. Keep a "counter" variable to mark which string is being checked now
3. In end check if any characters from both strings left to add

TC: O(n+m) -> traversing all characters in both strings
SC: O(n) -> create new string
*/

string mergeAlternately(string word1, string word2) 
{
        int n=word1.length();
        int m=word2.length();
        int i=0,j=0,counter=0;
        string ans="";
        while(i<n && j<m)
        {
            if(counter==0)
            {
                ans+=word1[i];
                counter=1;
                i++;
            }
            else
            {
                ans+=word2[j];
                counter=0;
                j++;
            }
        }
        while(i<n)
        {
            ans+=word1[i];
            i++;
        }
        while(j<m)
        {
            ans+=word2[j];
            j++;
        }
        return ans;
}
