#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
    unordered_set<int> set;
    
    for(int i=0; i<n; i++)
    {
        if(set.find(arr[i])!=set.end())
            return arr[i];
        set.insert(arr[i]);
    }
    
}
