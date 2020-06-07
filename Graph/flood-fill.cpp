//Flood Fill

/*
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image

Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.

*/

class Solution {
public:
    
    void flood(vector<vector<int>>& image,int i, int j, int col, int newcol)
    {
        if(i<0 || j<0 || i>=image.size() || j>=image[i].size() || image[i][j]!=col)
            return;
        else
        {
            image[i][j] = -1;
            flood(image,i-1,j,col,newcol);
            flood(image,i+1,j,col,newcol);
            flood(image,i,j-1,col,newcol);
            flood(image,i,j+1,col,newcol);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.size() == 0) return image;
        int n = image.size();
        int col = image[sr][sc];
        flood(image,sr,sc,col,newColor);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<image[i].size();j++)
            {
                if(image[i][j] == -1)
                    image[i][j] = newColor;
            }
        }
        return image;
    }
};
