#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &per, int n)
{
    int i=n-2;
    
    while(i>=0 && per[i]>=per[i+1])\
        i--;
    
    if(i>=0)
    {
        int j=n-1;
        while(j>=0 && per[j]<per[i])
            j--;
        
        swap(per[i], per[j]);
    }
    
    reverse(per.begin()+i+1, per.end());
    
    return per;
    //  Write your code here.
}
