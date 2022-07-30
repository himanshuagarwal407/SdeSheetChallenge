int unboundedKnapsack(int n, int w, vector<int> &value, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w+1, 0));
    for(int i=weight[0]; i<=w; i++)    
        dp[0][i]=(i/weight[0])*value[0];
    
    for(int i=1; i<n; i++)
    {
        for(int k=0; k<=w; k++)
        {
            int notTake = dp[i-1][k];
            int take=0;
            if(weight[i]<=k)
                take = value[i] + dp[i][k-weight[i]];
            
            dp[i][k] = max(take, notTake);
        }
    }
    
    return dp[n-1][w];
}
