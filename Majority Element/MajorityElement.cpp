#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
	// Write your code here.
    
    if(n==1)
        return arr[0];
    
    unordered_map<int,int> mp;
    
    for(int i=0; i<n; i++)
    {
        if(mp.find(arr[i])!=mp.end())
        {
            mp[arr[i]]++;
            if(mp[arr[i]]>n/2)
                return arr[i];
        }
        else
            mp[arr[i]]=1;
    }
    
    return -1;
}
