#include<bits/stdc++.h>

int solve(vector<vector<int>> triangle, int row, int col, int n, vector<vector<int>>& dp)
{
    if(row==n-1)
        return triangle[row][col];
    
    if(dp[row][col]!=-1)
        return dp[row][col];
    
    int a, b;
    a=solve(triangle, row+1, col, n, dp);
    b=solve(triangle, row+1, col+1, n, dp);
    
    return dp[row][col]=min(a, b) + triangle[row][col];
    
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int>> dp(n, vector<int>(n, -1));
    
    return solve(triangle, 0, 0, n, dp);
  }
