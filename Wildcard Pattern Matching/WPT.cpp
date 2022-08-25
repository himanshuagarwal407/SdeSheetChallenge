#include<bits/stdc++.h>

bool wildcardMatching(string p, string t)
{
    int  n=p.size(), m=t.size();
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    dp[0][0]=1;
    int i=1;
    while(i<=n && p[i-1]=='*')
    {
        dp[i][0]=1;
        i++;
    }
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(p[i-1]=='?' || p[i-1]==t[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
            {
                if(p[i-1]=='*')
                    dp[i][j]=dp[i-1][j]||dp[i][j-1];
            }
        }
    }
    
    return dp[n][m];
}
