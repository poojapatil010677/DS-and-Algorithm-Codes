/*

Island Perimeter

You are given a map in form of a two-dimensional integer grid where 1 
represents land and 0 represents water.Grid cells are connected 
horizontally/vertically (not diagonally). The grid is completely surrounded 
by water, and there is exactly one island (i.e., one or more connected land 
cells). The island doesn't have "lakes" (water inside that isn't connected 
to the water around the island). One cell is a square with side length 1. 
The grid is rectangular, width and height don't exceed 100. Determine the 
perimeter of the island.

Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Output: 16

*/

class Solution {
public:
    
    void perimeter(vector<vector<int>>& grid, int i,int j, int* peri)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size() || grid[i][j] == 0)
        {
            *peri = *peri + 1;
            return;
        }
        else if(grid[i][j]==1)
        {
            grid[i][j] = -1;
            perimeter(grid,i-1,j,peri);
            perimeter(grid,i+1,j,peri);
            perimeter(grid,i,j-1,peri);
            perimeter(grid,i,j+1,peri);
            return;
        }
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        int n = grid.size();
        int p=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                    perimeter(grid,i,j,&p);
            }
        }
        return p;
    }
};
