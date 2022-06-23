#include <bits/stdc++.h> 
#include <vector>

bool binarySearch(vector<int> v, int l, int r, int target)
{
    while(l<=r)
    {
        int mid = l+(r-l)/2;
        
        if(v[mid]==target)
            return true;
        else if(v[mid]>target)
            r=mid-1;
        else
            l=mid+1;
    }
    
    return false;
}

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    // Write your code here.
    
    for(int i=0; i<m; i++)
    {
        if(target>=mat[i][0] && target<=mat[i][n-1])
            return binarySearch(mat[i], 0, n-1, target);
    }
    
    return false;
}
