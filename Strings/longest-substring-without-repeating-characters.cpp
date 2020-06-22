/*

Longest substring without repeating characters

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

int lengthOfLongestSubstring(string s) {
    
        int n = s.length();
        unordered_map<char,int> m;
        int res = 0;
        int i = 0;
        for(int j=0;j<n;j++)
        {
            if(m.find(s[j])==m.end())
            {
                m[s[j]] = j;
                res = max(res,j-i+1);
            }
            
            else
            {
                i = max(i,m[s[j]]+1);
                res = max(res,j-i+1);
                m[s[j]] = j;
            }
        }
        return res;
    }
