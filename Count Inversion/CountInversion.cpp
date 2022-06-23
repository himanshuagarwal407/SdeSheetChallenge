#include <bits/stdc++.h> 

long long merge(long long * arr, int a[], int l, int mid, int r)
{
    int i=l, j=mid, k=l;
    long long count=0;
    
    while(i<mid && j<=r)
    {
        if(arr[i]<=arr[j])
            a[k++]=arr[i++];
        else
        {
            a[k++]=arr[j++];
            count += (mid-i);
        }
    }
    
    while(i<mid)
        a[k++]=arr[i++];
    while(j<=r)
        a[k++]=arr[j++];
    
    for(i=l; i<=r; i++)
        arr[i]=a[i];
    
    return count;
}

long long mergeSort(long long *arr, int a[], int l, int r)
{
    long long mid, count=0;
    
    if(l<r)
    {
        mid = l+(r-l)/2;
        
        count += mergeSort(arr, a, l, mid);
        count += mergeSort(arr, a, mid+1, r);
        
        count += merge(arr, a, l, mid+1, r);
    }
    
    return count;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    int a[n];
    long long ans=mergeSort(arr, a, 0, n-1);
    
    return ans;
}
