/*

Longest common prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"

*/

 string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        string res = "";
        if(n==0) return res;
        if(n==1) return strs[0];
        int i=0;
        int flag = 1;
        while(flag)
        {
            for(int j=1;j<n;j++)
            {
                if((i+1)>strs[j].size() || strs[j][i]!=strs[0][i])
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)
            {
                res+=strs[0][i];
                i++;
            }
        }
        return res;
    }
