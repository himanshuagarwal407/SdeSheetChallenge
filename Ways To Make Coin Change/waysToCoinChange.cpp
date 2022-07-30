#include<bits/stdc++.h>

long solve(int *demo, int ind, int k, vector<vector<long>>& dp)
{
    if(k==0)
        return 1;
    if(ind==0)
    {
        if(k==demo[0] || k%demo[0]==0)
            return 1;
        return 0;
    }
    
    if(dp[ind][k]!=-1)
        return dp[ind][k];
    
    long notTake = solve(demo, ind-1, k, dp);
    long take = 0;
    if(demo[ind]<=k)
        take = solve(demo, ind, k-demo[ind], dp);
    
    return dp[ind][k]=take+notTake;
}

long countWaysToMakeChange(int *demo, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value+1, -1));
    
    return solve(demo, n-1, value, dp);
}
