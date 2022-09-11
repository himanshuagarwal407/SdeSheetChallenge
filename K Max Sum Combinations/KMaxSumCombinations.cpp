#include <bits/stdc++.h>

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    priority_queue<pair<int, pair<int, int>>> pq;
    set<pair<int, int>> st;
    vector<int> ans;
    
    pq.push({a[n-1]+b[n-1], {n-1, n-1}});
    st.insert({n-1, n-1});
    
    while(k--)
    {
        pair<int, pair<int, int>> temp = pq.top();
        pq.pop();
        
        ans.push_back(temp.first);
        
        int x=temp.second.first;
        int y=temp.second.second;
        
        pair<int, int> tp = {x-1, y};
        if(st.find(tp)==st.end())
        {
            int sum = a[x-1]+b[y];
            pq.push({sum, tp});
            st.insert(tp);
        }
        
        tp={x, y-1};
        if(st.find(tp)==st.end())
        {
            int sum=a[x]+b[y-1];
            pq.push({sum, tp});
            st.insert(tp);
        }
        
    }
    
    return ans;
}
