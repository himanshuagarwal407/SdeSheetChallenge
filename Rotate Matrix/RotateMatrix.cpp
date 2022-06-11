#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int r=0, c=0;
    int prev, curr;
    
    while(r<n && c<m)
    {
        if(r+1==n || c+1==m)
            break;
        
        prev=mat[r+1][c];
        for(int i=c; i<m; i++)
        {
            curr=mat[r][i];
            mat[r][i]=prev;
            prev=curr;
        }
        r++;
        
        for(int i=r; i<n; i++)
        {
            curr=mat[i][m-1];
            mat[i][m-1]=prev;
            prev=curr;
        }
        m--;
        
        if(r<n)
        {
            for(int i=m-1; i>=c; i--)
            {
                curr=mat[n-1][i];
                mat[n-1][i]=prev;
                prev=curr;
            }
        }
        n--;
        
        if(c<m)
        {
            for(int i=n-1; i>=r; i--)
            {
                curr=mat[i][c];
                mat[i][c]=prev;
                prev=curr;
            }
        }
        c++;
    }
    // Write your code here

}
