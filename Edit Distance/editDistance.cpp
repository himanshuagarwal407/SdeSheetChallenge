int solve(string& s, string& t, int i, int j, vector<vector<int>>& dp)
{
    if(i<0)
        return j+1;
    if(j<0)
        return i+1;
        
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    if(s[i]==t[j])
        return dp[i][j] = 0+solve(s, t, i-1, j-1, dp);
    
    return dp[i][j] = 1+min(solve(s, t, i-1, j-1, dp), min(solve(s, t, i-1, j, dp), solve(s, t, i, j-1, dp)));
}

int editDistance(string str1, string str2)
{
    int n=str1.size(), m=str2.size();
    
    vector<vector<int>> dp(n, vector<int>(m, -1));
    
    return solve(str1, str2, n-1, m-1, dp);
}
