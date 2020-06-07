// max area of island

/*

Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's 
(representing land) connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.Find the 
maximum area of an island in the given 2D array. (If there is no island, 
the maximum area is 0.)

*/

class Solution {
public:
    
    void maxArea(vector<vector<int>>& grid,int* area,int i, int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size() || grid[i][j]==0)
            return;
        else
        {
            grid[i][j] = 0;
            *area = *area + 1;
            maxArea(grid,area,i-1,j);
            maxArea(grid,area,i+1,j);
            maxArea(grid,area,i,j-1);
            maxArea(grid,area,i,j+1);
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        int n = grid.size();
        int max_area = 0;
        int area = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                area = 0;
                if(grid[i][j] == 1)
                {
                    maxArea(grid,&area,i,j);
                    if(area>max_area) max_area = area;
                }
            }
        }
        return max_area;
    }
};

