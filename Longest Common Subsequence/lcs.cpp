#include<bits/stdc++.h>

int lcs(string s, string t)
{
    int n=s.size();
    int m=t.size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int i=0; i<n; i++)
        if(s[i]==t[0])
            dp[i][0]=1;
    for(int i=0; i<m; i++)
        if(t[i]==s[0])
            dp[0][i]=1;
    
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            if(s[i]==t[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    return dp[n-1][m-1];
}
