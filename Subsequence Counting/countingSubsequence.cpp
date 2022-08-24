#include<bits/stdc++.h>
int mod = 1e9+7;

int subsequenceCounting(string &t, string &s, int lt, int ls) {
    
    vector<vector<int>> dp(lt+1, vector<int>(ls+1, 0));
    for(int i=0; i<lt; i++)
    {
        if(t[i]==s[0])
            dp[i][0]=1;
    }
    
    for(int i=1; i<lt; i++)
    {
        for(int j=0; j<ls; j++)
        {
            if(t[i]==s[j])
                dp[i][j]=(dp[i][j]+dp[i-1][j-1]+dp[i-1][j])%mod;
            else
                dp[i][j]=dp[i-1][j]%mod;
        }
    }
    
    return dp[lt-1][ls-1];
} 
