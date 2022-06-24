#include <bits/stdc++.h>

int solve(int x, int n, int m)
{
    if(n==0)
        return 1;
    
    long long r = solve(x, n/2, m);
    
    if(n&1)
        return (x*((r*r)%m))%m;
    else
        return (r%m*r%m)%m;
}

int modularExponentiation(int x, int n, int m) {
	// Write your code here.
    return solve(x,n,m);
}
