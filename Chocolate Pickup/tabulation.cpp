#include<bits/stdc++.h>

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    
    for(int j=0; j<c; j++)
    {
        for(int k=0; k<c; k++)
        {
            if(j==k)
                dp[r-1][j][k]=grid[r-1][j];
            else
                dp[r-1][j][k]=grid[r-1][j]+grid[r-1][k];
        }
    }
    
    for(int i=r-2; i>=0; i--)
    {
        for(int j1=0; j1<c; j1++)
        {
            for(int j2=0; j2<c; j2++)
            {
                int maxi=0;
                for(int dj1=-1; dj1<=1; dj1++)
                {
                    for(int dj2=-1; dj2<=1; dj2++)
                    {
                        int x=0;
                        if(j1==j2)
                            x = grid[i][j1];
                        else
                            x = grid[i][j1] + grid[i][j2];
                        
                        if(j1+dj1>=0 && j1+dj1<c && j2+dj2>=0 && j2+dj2<c)
                            x += dp[i+1][j1+dj1][j2+dj2];
                        else
                            x += -1e8;
                        
                        maxi = max(maxi, x);
                    }
                }
                
                dp[i][j1][j2]=maxi;
            }
        }
    }
    
    return dp[0][0][c-1];
}
