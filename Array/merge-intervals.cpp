/*

Merge Intervals

Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

*/

class Solution {
public:
    
    static bool sortcol(const vector<int>& v1,const vector<int>& v2)
    {
        return v1[0]<v2[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.size()<=1) return intervals;
        sort(intervals.begin(),intervals.end(),sortcol);
        vector<int> temp(2);
        temp[0] = intervals[0][0];
        temp[1] = intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=temp[1])
            {
                temp[1] = max(temp[1],intervals[i][1]);
            }
            else
            {
                res.push_back(temp);
                temp[0] = intervals[i][0];
                temp[1] = intervals[i][1];
            }
        }
        res.push_back(temp);
        return res;
    }
};
