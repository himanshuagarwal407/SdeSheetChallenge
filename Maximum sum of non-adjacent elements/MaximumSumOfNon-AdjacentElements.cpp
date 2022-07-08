int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    
    int prev=nums[0];
    int prev2=0;
    
    for(int i=1; i<n; i++)
    {
        int take=nums[i]+prev2;
        int nTake=0+prev;
        
        int curr=max(take, nTake);
        
        prev2=prev;
        prev=curr;
    }
    
    return prev;
}
