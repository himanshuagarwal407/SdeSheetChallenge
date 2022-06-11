#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
    vector<vector<long long int>> v;
    v.push_back({1});
    
    if(n==1)
        return v;
    
    v.push_back({1,1});
    
    for(int i=3; i<=n; i++)
    {
        vector<long long int> v1 = v[v.size()-1];
        vector<long long int> v2(i);
        
        v2[0]=1, v2[i-1]=1;
        for(int j=1; j<i-1; j++)
        {
            v2[j]=v1[j]+v1[j-1];
        }
        
        v.push_back(v2);
    }
    
    return v;
  // Write your code here.
}
