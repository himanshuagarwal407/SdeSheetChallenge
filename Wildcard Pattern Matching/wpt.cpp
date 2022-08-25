#include<bits/stdc++.h>

bool solve(string p, string t, int i, int j, vector<vector<int>>& dp)
{
    if(i<0 && j<0)
        return true;
    if(i<0)
        return false;
    if(j<0)
    {
        bool f=true;
        while(i>=0)
        {
            if(p[i]!='*')
                f=false;
            i--;
        }
        
        return f;
    }
    
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    if(p[i]=='?')
        return dp[i][j]=solve(p, t, i-1, j-1, dp);
    if(p[i]=='*')
    {
        bool f1 = solve(p, t, i-1, j, dp);
        bool f2 = solve(p, t, i, j-1, dp);
        
        return dp[i][j]=f1||f2;
    }
    else
    {
        if(p[i]==t[j])
            return dp[i][j]=solve(p, t, i-1, j-1, dp);
        return dp[i][j]=false;
    }
    
    return dp[i][j]=true;
}

bool wildcardMatching(string pattern, string text)
{
    int  n=pattern.size(), m=text.size();
    
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(pattern, text, n-1, m-1, dp);
}
