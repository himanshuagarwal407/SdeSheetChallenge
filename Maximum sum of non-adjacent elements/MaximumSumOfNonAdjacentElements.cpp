int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int> dp(n,-1);
    
    dp[0]=nums[0];
    dp[1]=max(nums[1], dp[0]);
    
    for(int i=2; i<n; i++)
    {
        int take=nums[i]+dp[i-2];
        int nTake=0+dp[i-1];
        
        dp[i]=max(take, nTake);
    }
    
    return dp[n-1];
}
