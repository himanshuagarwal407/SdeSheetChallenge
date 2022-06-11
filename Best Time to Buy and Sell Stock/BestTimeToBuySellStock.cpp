#include <bits/stdc++.h> 
int maximumProfit(vector<int> &p){
    int n=p.size();
    
    int cp=p[0];
    int profit=0;
    
    for(int i=1; i<n; i++)
    {
        if(p[i]>cp)
            profit = max(profit, p[i]-cp);
        else if(p[i]<cp)
            cp=p[i];
    }
    
    return profit;
    // Write your code here.
}
