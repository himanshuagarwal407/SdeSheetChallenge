#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    if(n==0)
        return 0;
    
    int len=1, maxLen=1;
    sort(arr.begin(), arr.end());
    
    for(int i=1; i<n; i++)
    {
        if(arr[i]==arr[i-1])
            continue;
        if(arr[i]==arr[i-1]+1)
            len++;
        else
            len=1;
        
        maxLen=max(len, maxLen);
    }
    
    return maxLen;
}
