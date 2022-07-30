int solve(vector<int> arr, int ind, int k, vector<vector<int>>& dp)
{
    if(ind==0)
    {
        if(k==0 && arr[0]==0)
            return 2;
        if(k==0 || k==arr[0])
            return 1;
        return 0;
    }
    
    if(dp[ind][k]!=-1)
        return dp[ind][k];
    
    int notTake = solve(arr, ind-1, k, dp);
    int take = 0;
    if(arr[ind]<=k)
        take = solve(arr, ind-1, k-arr[ind], dp);
    
    return dp[ind][k]=notTake+take;
}

int targetSum(int n, int target, vector<int>& arr) {
    int sum=0;
    for(auto x:arr)
        sum+=x;
    
    if(sum-target<0)
        return 0;
    if((sum-target)%2==1)
        return 0;
    int s=(sum-target)/2;
    
    vector<vector<int>>dp (n, vector<int> (s+1, -1));
    
    return solve(arr, n-1, s, dp);
}
