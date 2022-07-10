#include<bits/stdc++.h>
int mod = 1e9+7;

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector< vector< int> > dp(n, vector<int>(m, -1));
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i==0 && j==0)
                dp[i][j]==1;        
            else if(mat[i][j]==-1)
                dp[i][j]=0;
            else
            {
                int left = (i>0) ? dp[i-1][j] : 0;
                int right = (j>0) ? dp[i][j-1] : 0;
                
                 dp[i][j]=(left+right)%mod;   
            }
        }
    }
    
    return abs(dp[n-1][m-1]);
}
