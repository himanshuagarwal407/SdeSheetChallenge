#include<bits/stdc++.h>

int minimumElements(vector<int> &num, int x)
{
    if(x==0)
        return 0;
    
    int n=num.size();
    sort(num.begin(), num.end());
    
    vector<vector<int>> dp(n, vector<int>(x+1, 0));
    for(int i=0; i<=x; i++)
    {
        if(i%num[0]==0)
            dp[0][i] = i/num[0];
        else
            dp[0][i] = 1e9;
    }
    
    for(int i=1; i<n; i++)
    {
        for(int k=0; k<=x; k++)
        {
            int notTake = dp[i-1][k];
            int take = 1e9;
            if(num[i]<=k)
                take = 1+dp[i][k-num[i]];
            
            dp[i][k]=min(notTake, take);
        }
    }
    
    int ans = dp[n-1][x];
    
    if(ans && ans!=1e9)
        return ans;
    return -1;
}
