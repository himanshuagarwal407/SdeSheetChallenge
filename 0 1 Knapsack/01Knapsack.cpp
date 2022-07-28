int solve(vector<int> weight, vector<int> value, int ind, int W, vector<vector<int>>& dp)
{
    if(W==0)
        return 0;
    if(ind==0)
    {
        if(weight[0]<=W)
            return value[0];
        return 0;
    }
    
    if(dp[ind][W]!=-1)
        return dp[ind][W];
    
    int notPick = solve(weight, value, ind-1, W, dp);
    int pick = 0;
    if(weight[ind]<=W)
        pick = value[ind] + solve(weight, value, ind-1, W-weight[ind], dp);
    
    return dp[ind][W] = max(pick, notPick);
}
    
int knapsack(vector<int> weight, vector<int> value, int n, int W) 
{
    vector<vector<int>> dp(n, vector<int>(W+1, -1));
    
    return solve(weight, value, n-1, W, dp);
	// Write your code here
}
