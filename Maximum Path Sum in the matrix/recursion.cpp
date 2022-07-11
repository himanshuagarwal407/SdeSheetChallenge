#include<bits/stdc++.h>

int solve(vector<vector<int>> matrix, int n, int m, int row, int col)
{
    if(col<0 || col>=m)
        return INT_MIN;
    
    if(row==n-1)
        return matrix[n-1][col];
    
    int left = solve(matrix, n, m, row+1, col-1);
    int down = solve(matrix, n, m, row+1, col);
    int right = solve(matrix, n, m, row+1, col+1);
    
    return matrix[row][col] + max(left, max(down, right));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    int ans=INT_MIN;
    
    for(int i=0; i<m; i++)
        ans=max(ans, solve(matrix, n, m, 0, i));
    
    return ans;
}
