int mod = (int)(1e9+7);

int countPartitions(int n, int d, vector<int> &arr) {
    int sum=0;
    for(int i=0; i<n; i++)
        sum+=arr[i];
    
    if((sum-d)<0 || (sum-d)%2!=0)
        return 0;
    int s1=(sum-d)/2;
    
    vector<vector<int>> dp(n, vector<int>(s1+1, 0));
    if(arr[0]==0)
        dp[0][0]=2;
    else
        dp[0][0]=1;
    if(arr[0]!=0 && arr[0]<=s1)
        dp[0][arr[0]]=1;
    
    for(int i=1; i<n; i++)
    {
        for(int k=0; k<=s1; k++)
        {
            int notTake = dp[i-1][k];
            int take=0;
            if(arr[i]<=k)
                take=dp[i-1][k-arr[i]];
            
            dp[i][k] = (take+notTake)%mod;
        }
    }
    
    return dp[n-1][s1];
}
