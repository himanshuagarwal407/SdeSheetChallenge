int findWays(vector<int> &num, int tar)
{
    int n=num.size();
    vector<vector<int>> dp(n, vector<int>(tar+1, 0));
    
    for(int i=0; i<n; i++)
        dp[i][0]=1;
    if(num[0]<=tar)
        dp[0][num[0]]=1;
    
    for(int i=1; i<n; i++)
    {
        for(int k=0; k<=tar; k++)
        {
            int notTake = dp[i-1][k];
            int take=0;
            if(num[i]<=k)
                take = dp[i-1][k-num[i]];
            
            dp[i][k]=take+notTake;
        }
    }
    
    return dp[n-1][tar];
}
