int maximumProfit(int n, int fee, vector<int> &prices) {
    vector<vector<int>> dp(n+1, vector<int>(2, 0));
    
    for(int i=n-1; i>=0; i--)
    {
        for(int j=0; j<=1;j++)
        {
            if(j)
                dp[i][j] = max(dp[i+1][0]-prices[i], dp[i+1][1]);
            else
                dp[i][j] = max(dp[i+1][1]+prices[i]-fee, dp[i+1][0]);
        }
    }
    
    return dp[0][1];
}
