#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    int n=arr.size();
    vector<int> prefix(n);
    prefix[0]=arr[0];
    
    for(int i=1; i<n; i++)
        prefix[i]=prefix[i-1]^arr[i];    
    
    map<int,int> mp;
    int count=0;
    
    for(int i=0; i<n; i++)
    {
        if(prefix[i]==x)
            count++;
        
        if(mp.find(prefix[i]^x)!=mp.end())
            count += mp[prefix[i]^x];
        
        mp[prefix[i]]++;
    }
    
    return count;
    //    Write your code here.
}
