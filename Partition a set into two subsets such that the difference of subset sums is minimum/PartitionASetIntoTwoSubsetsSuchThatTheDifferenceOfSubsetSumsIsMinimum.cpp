int minSubsetSumDifference(vector<int>& arr, int n)
{
    int tsum=0;
    
    for(int i=0; i<n; i++)
        tsum+=arr[i];
    
    vector<vector<bool>> dp(n, vector<bool>(tsum+1, false));
    
    for(int i=0; i<n; i++)
        dp[i][0]=true;
    if(arr[0]<=tsum) 
        dp[0][tsum]=true;
    
    for(int i=1; i<n; i++)
    {
        for(int k=1; k<=tsum; k++)
        {
            bool notTake =  dp[i-1][k];
            bool take = false;
            if(arr[i]<=k)
                take=dp[i-1][k-arr[i]];
            
            dp[i][k]=take || notTake;
        }
    }
    
    int mini=1e9;
    for(int i=0; i<=tsum; i++)
    {
        if(dp[n-1][i]==true)
            mini = min(mini, abs((tsum-i)-i));
    }
    
    return mini;
	// Write your code here.
}
