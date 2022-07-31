int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n+1, 0));
    int W=n;
    for(int i=0; i<=W; i++)
        dp[0][i]=i*price[0];
    
    for(int i=1; i<n; i++)
    {
        for(int k=0; k<=W; k++)
        {
            int notTake=dp[i-1][k];
            int take=0;
            if(i+1<=k)
                take = price[i] + dp[i][k-(i+1)];
            
            dp[i][k]=max(notTake, take);
        }
    }
    
    return dp[n-1][W];
}
