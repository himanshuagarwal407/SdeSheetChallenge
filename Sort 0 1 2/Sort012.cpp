#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
    int c0=0, c1=0, c2=0;
    
    for(int i=0; i<n; i++)
    {
        if(arr[i]==0)
            c0++;
        else if(arr[i]==1)
            c1++;
        else if(arr[i]==2)
            c2++;
    }
    
    int i=0;
    while(i<c0)
    {
        arr[i]=0;
        i++;
        
    }
    while(i<c0+c1)
    {
        arr[i]=1;
        i++;
    }
    while(i<c0+c1+c2)
    {
        arr[i]=2;
        i++;
    }
    
    
   //   Write your code here
}
