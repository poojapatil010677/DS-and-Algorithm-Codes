/*

A string S of lowercase English letters is given. We want to partition this string 
into as many parts as possible so that each letter appears in at most one part, and 
return a list of integers representing the size of these parts.

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it 
splits S into less parts.

*/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        int arr[26] = {0};
        for(int i=0;i<S.length();i++)
        {
            arr[S[i]-'a'] = i;
        }
        int i=0;
        while(i<S.length())
        {
            int end = arr[S[i]-'a'];
            int j = i;
            while(j!=end)
            {
                end = max(end,arr[S[j]-'a']);
                j++;
            }
            res.push_back(j-i+1);
            i = j+1;
        }
        cout << arr[0];
        return res;
    }
};
