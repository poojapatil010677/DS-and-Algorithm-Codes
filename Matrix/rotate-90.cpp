/*

Rotate a matrix by 90 degrees clockwise

time complexity : O(r*c)

*/

class Solution {
public:
    void swap(int* a,int* b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    
    void transpose(vector<vector<int>>& mat)
    {
        int r = mat.size();
        int c = mat[0].size();
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c-i;j++)
            {
                swap(&mat[i][j],&mat[c-1-j][c-1-i]);
            }
        }
    }
    
    void reversecol(vector<vector<int>>& mat)
    {
        int r = mat.size();
        int c = mat[0].size();
        
        for(int i=0;i<c;i++)
        {
            for(int j=0;j<(r/2);j++)
            {
                swap(&mat[j][i],&mat[r-j-1][i]);
            }
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reversecol(matrix);
    }
};
