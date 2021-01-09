class Solution {
    public int lengthOfLongestSubstring(String s) {
        
        int n = s.length();
        
        int res = 0;
        
        for(int i=0;i<n;i++)
        {
            boolean[] visited = new boolean[256];
            
            for(int j=i;j<n;j++)
            {
                if(visited[s.charAt(j)] == true)
                    break;
                
                else {
                    visited[s.charAt(j)] = true;
                    res = Math.max(res,j-i+1);
                }
            }
        }
        
        return res;
        
    }
}