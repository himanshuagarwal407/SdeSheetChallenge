int targetSum(int n, int target, vector<int>& arr) {
    int sum=0;
    for(auto x:arr)
        sum+=x;
    
    if(sum-target<0)
        return 0;
    if((sum-target)%2==1)
        return 0;
    int s=(sum-target)/2;
    
    vector<vector<int>>dp (n, vector<int> (s+1, 0));
    if(arr[0]==0)
        dp[0][0]=2;
    else
        dp[0][0]=1;
    if(arr[0]!=0 && arr[0]<=s)
        dp[0][arr[0]]=1;
    
    for(int i=1; i<n; i++)
    {
        for(int k=0; k<=s; k++)
        {
            int notTake = dp[i-1][k];
            int take = 0;
            if(arr[i]<=k)
                take = dp[i-1][k-arr[i]];
            
            dp[i][k]=take+notTake;
        }
    }
    
    return dp[n-1][s];
}
