#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long sum=arr[0];
    long long maxSum=sum;
    
    for(int i=1; i<n; i++)
    {
        sum+=arr[i];
        if(sum<0)
        {
            sum=0;
        }
        
        maxSum=max(maxSum, sum);
    }
    
    return maxSum;
}
