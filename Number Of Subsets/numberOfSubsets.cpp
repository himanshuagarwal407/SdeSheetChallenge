int solve(vector<int> num, int target, int ind, vector<vector<int>>& dp)
{
    if(ind==0)
    {
        if(target==0 && num[0]==0)
            return 2;
        if(target==0 || target==num[0])
            return 1;
        return 0;
    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
    
    int notTake = solve(num, target, ind-1, dp);
    int take=0;
    if(num[ind]<=target)
        take = solve(num, target-num[ind], ind-1, dp);
    
    return dp[ind][target] = take+notTake;
}

int findWays(vector<int> &num, int tar)
{
    int n=num.size();
    vector<vector<int>> dp(n, vector<int>(tar+1, -1));
    
    return solve(num, tar, n-1, dp);
}
