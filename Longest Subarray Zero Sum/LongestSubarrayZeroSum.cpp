#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {
    int n=arr.size();
    
    int sum=0, len=0, maxLen=0;
    map<int,int> mp;
    mp[0]=-1;
    
    for(int i=0; i<n; i++)
    {
        sum+=arr[i];
        
        if(mp.find(sum)!=mp.end())
        {
            len=i-mp[sum];
            maxLen=max(len, maxLen);
            len=0;
        }
        else
            mp[sum]=i;
    }
    
    return maxLen;
  // Write your code here

}
