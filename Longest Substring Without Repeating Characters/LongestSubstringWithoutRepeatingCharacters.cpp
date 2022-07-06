#include <bits/stdc++.h> 
int uniqueSubstrings(string s)
{
    int n=s.size(), l=0, h=0, ans=0;
    map<char, int> mp;
    
    while(l<=h && h<n)
    {
        mp[s[h]]++;
        
        while(mp[s[h]]>1)
        {
            mp[s[l]]--;
            l++;
        }
        
        ans=max(ans, h-l+1);
        h++;
    }
    
    return ans;
    //Write your code here
}
