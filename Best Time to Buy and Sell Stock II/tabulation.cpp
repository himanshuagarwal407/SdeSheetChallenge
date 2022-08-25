#include<bits/stdc++.h>

long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n+1, vector<long>(2, 0));
    dp[n][0]=0;
    dp[n][1]=0;
    
    for(int i=n-1; i>=0; i--)
    {
        for(int j=0; j<=1; j++)
        {
            if(j)
                dp[i][j]=max(dp[i+1][0]-values[i], dp[i+1][1]);
            else
                dp[i][j]=max(dp[i+1][1]+values[i], dp[i+1][0]);
        }
    }
    
    return dp[0][1];
}
