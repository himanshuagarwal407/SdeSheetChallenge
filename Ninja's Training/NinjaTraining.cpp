int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));
    
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][1], points[0][0]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
    
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<4; j++)
        {
            dp[i][j]=0;
            
            for(int k=0; k<3; k++)
            {
                if(j!=k)
                {
                    int point = points[i][k] + dp[i-1][k];
                    dp[i][j] = max( dp[i][j], point);
                }
            }
        }
    }
    
    return dp[n-1][3];
    // Write your code here.
}
