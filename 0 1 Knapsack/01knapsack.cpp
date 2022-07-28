int knapsack(vector<int> weight, vector<int> value, int n, int W) 
{
    vector<vector<int>> dp(n, vector<int>(W+1, 0));
    for(int i=weight[0]; i<=W; i++)
        dp[0][i] = value[0];
    
    for(int i=1; i<n; i++)
    {
        for(int w=0; w<=W; w++)
        {
            int notPick = dp[i-1][w];
            int pick=0;
            if(weight[i]<=w)
                pick = value[i] + dp[i-1][w-weight[i]];
            
            dp[i][w] = max(pick, notPick);
        }
    }
    
    return dp[n-1][W];
}
