#include<bits/stdc++.h>
int mod = 1e9+7;

int solve(string t, string s, int n, int m, vector<vector<int>>& dp)
{
    if(m<0)
        return 1;
    if(n<0)
        return 0;
    
    if(dp[n][m]!=-1)
        return dp[n][m];
    
    if(t[n]==s[m])
        return dp[n][m] = (solve(t,s, n-1, m-1, dp)+solve(t, s, n-1, m, dp))%mod;
    else 
        return dp[n][m] = solve(t, s, n-1, m, dp)%mod;
}

int subsequenceCounting(string &t, string &s, int lt, int ls) {
    vector<vector<int>> dp(lt+1, vector<int>(ls+1, -1));
    return solve(t, s, lt-1, ls-1, dp);
} 
