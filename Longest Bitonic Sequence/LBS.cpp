int solve(vector<int> arr, int n, int ind, int prev, int a, vector<vector<vector<int>>>& dp)
{
    if(ind>=n)
        return 0;

    if(dp[ind][prev+1][a]!=-1)
        return dp[ind][prev+1][a];
    
    int take=0;
    if(prev==-1 || (arr[prev]<arr[ind] && a==1))
        take = max(take, 1+solve(arr, n, ind+1, ind, 1, dp));
    else if(arr[prev]>arr[ind])
        take = max(take, 1+solve(arr, n, ind+1, ind, 0, dp));
    int notTake = solve(arr, n, ind+1, prev, a, dp);
    
    return dp[ind][prev+1][a] = max(take, notTake);
}
    
int longestBitonicSequence(vector<int>& arr, int n) {
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (n+1, vector<int> (2, -1)));
    
    return solve(arr, n, 0, -1, 1, dp);
	  // Write your code here.	   
} 
