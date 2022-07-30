#include<bits/stdc++.h>

long countWaysToMakeChange(int *demo, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value+1, 0));
    for(int i=0; i<n; i++)
        dp[i][0]=1;
    for(int i=0; i<=value; i++)
    {
        if(i%demo[0]==0)
            dp[0][i]=1;
    }
    
    for(int ind=1; ind<n; ind++)
    {
        for(int k=0; k<=value; k++)
        {
            long notTake = dp[ind-1][k];
            long take = 0;
            if(demo[ind]<=k)
                take = dp[ind][k-demo[ind]];
            
            dp[ind][k] = notTake + take;
        }
    }
    
    return dp[n-1][value];
}
