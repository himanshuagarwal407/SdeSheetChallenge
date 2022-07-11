#include<bits/stdc++.h>

int solve(vector<vector<int>> matrix, int n, int m, int row, int col, vector<vector<int>>& dp)
{
    if(col<0 || col>=m)
        return INT_MIN;
    
    if(row==n-1)
        return matrix[n-1][col];
    
    if(dp[row][col]!=-1)
        return dp[row][col];
    
    int left = solve(matrix, n, m, row+1, col-1, dp);
    int down = solve(matrix, n, m, row+1, col, dp);
    int right = solve(matrix, n, m, row+1, col+1, dp);
    
    return dp[row][col] = matrix[row][col] + max(left, max(down, right));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    int ans=INT_MIN;
    
    vector<vector<int>> dp(n, vector<int>(m, -1));
    
    for(int i=0; i<m; i++)
        ans=max(ans, solve(matrix, n, m, 0, i, dp));
    
    return ans;
}
