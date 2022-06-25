#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	// Write your code here.
    if(m==1 || n==1)
        return 1;
    
    int path[m][n];
        
    for(int i=0; i<n-1; i++)
        path[m-1][i]=1;
    for(int i=0; i<m-1; i++)
        path[i][n-1]=1;

    for(int i=m-2; i>=0; i--)
        for(int j=n-2; j>=0; j--)
            path[i][j]=path[i+1][j]+path[i][j+1];

    return path[0][0];
}
