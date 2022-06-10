#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
    int n=arr.size();
    vector<vector<int>> res;
    
    sort(arr.begin(), arr.end());
    
    for(int i=0; i<n; i++)
    {
        int x=arr[i];
        for(int j=i+1; j<n; j++)
        {
            if(x+arr[j]==s)
                res.push_back({x, arr[j]});
            if(x+arr[j]>s)
                break;
        }
    }
    
    return res;
   // Write your code here.
}
