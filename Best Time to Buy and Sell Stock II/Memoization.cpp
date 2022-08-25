#include<bits/stdc++.h>

long solve(long *values, int ind, int buy, int n, vector<vector<long>>& dp)
{
    if(ind==n)
        return 0;
    
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
    
    if(buy)
    {
        return dp[ind][buy]=max(solve(values, ind+1, 0, n, dp)-values[ind], solve(values, ind+1, 1, n, dp));
    }
    else
    {
        return dp[ind][buy]=max(solve(values, ind+1, 1, n, dp)+values[ind], solve(values, ind+1, 0, n, dp));
    }
}

long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n, vector<long>(2, -1));
    
    return solve(values, 0, 1, n, dp);
}
