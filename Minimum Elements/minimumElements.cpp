#include<bits/stdc++.h>

int solve(vector<int> num, int ind, int x, vector<vector<int>>& dp)
{
    if(ind!=0 && x==0)
        return 0;
    if(ind==0)
    {
        if(x==0 || num[0]==x)
            return 1;
        else if(x%num[0]==0)
            return x/num[0];
        return 1e9;;
    }
    
    if(dp[ind][x]!=-1)
        return dp[ind][x];
    
    int notTake = solve(num, ind-1, x, dp);
    int take = 1e9;
    if(num[ind]<=x)
        take = 1+solve(num, ind, x-num[ind], dp);
    
    return dp[ind][x] = min(take, notTake);
}

int minimumElements(vector<int> &num, int x)
{
    if(x==0)
        return 0;
    
    int n=num.size();
    sort(num.begin(), num.end());
    
    vector<vector<int>> dp(n, vector<int>(x+1, -1));
    int ans = solve(num , n-1, x, dp);
    
    if(ans && ans!=1e9)
        return ans;
    return -1;
}
