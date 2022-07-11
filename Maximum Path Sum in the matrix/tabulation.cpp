#include<bits/stdc++.h>

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    int ans=INT_MIN;
    
    vector<vector<int>> dp(n, vector<int>(m));
    for(int i=0; i<m; i++)
        dp[0][i]=matrix[0][i];
    
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int ld = (j>0) ? dp[i-1][j-1] : INT_MIN;
            int up = dp[i-1][j];
            int rd = (j<m-1) ? dp[i-1][j+1] : INT_MIN;
            
            dp[i][j] = max(up, max(ld, rd)) + matrix[i][j];
        }
    }
    
    for(int i=0; i<m; i++)
        ans=max(ans, dp[n-1][i]);
    
    return ans;
}
