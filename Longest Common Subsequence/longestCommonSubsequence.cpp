#include<bits/stdc++.h>

int solve(string s, int ind1, string t, int ind2, vector<vector<int>>& dp)
{
    if(ind1==0 || ind2==0)
    {
        if(s[ind1]==t[ind2])
            return 1;
        return 0;
    }
    
    if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];
    
    if(s[ind1]==t[ind2])
        return dp[ind1][ind2]=1+solve(s, ind1-1, t, ind2-1, dp);
    return dp[ind1][ind2]=max(solve(s, ind1-1, t, ind2, dp), solve(s, ind1, t, ind2-1, dp));
}

int lcs(string s, string t)
{
    int n=s.size();
    int m=t.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(s, n-1, t, m-1, dp);
	//Write your code here
}
