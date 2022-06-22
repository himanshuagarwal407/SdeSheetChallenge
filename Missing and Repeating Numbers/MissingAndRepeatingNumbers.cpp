#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here
    pair<int,int> ans;
    
    //for finding repeating element
	for(int i=0; i<n; i++)
    {
        if(arr[abs(arr[i])-1]>0)
            arr[abs(arr[i])-1]*=-1;
        else
            ans.second=abs(arr[i]);
    }
    
    //for finding missing element
    for(int i=0; i<n; i++)
        if(arr[i]>0)
            ans.first=i+1;
    
    return ans;
}
