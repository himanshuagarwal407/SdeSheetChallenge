#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int n=arr.size();
    if(n==1)
        return arr;
    
    unordered_map<int,int> mp;
    set<int> s;
    vector<int> v;
    
    for(int i=0; i<n; i++)
    {
        if(mp.find(arr[i])!=mp.end())
        {
            mp[arr[i]]++;
            if(mp[arr[i]]>n/3)
                s.insert(arr[i]);
        }
        else
        {
            mp[arr[i]]=1;
            if(mp[arr[i]]>n/3)
                s.insert(arr[i]);
        }
    }
    
    for(auto x:s)
        v.push_back(x);
    return v;
}
