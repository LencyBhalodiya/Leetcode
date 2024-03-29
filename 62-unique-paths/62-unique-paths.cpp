class Solution {
private:
    int solve(int m , int n,vector<vector<int>> &dp)
    {
        if(m == 0 && n == 0)
            return 1;
        if(m < 0 || n < 0)
            return 0;
        
         if(dp[m][n] != -1)
             return dp[m][n];
        
        int left = solve(m , n-1,dp);
        int up = solve(m-1, n,dp);
        
        return dp[m][n] = left + up;
    }
    int tabulation(int m , int n)
    {
       vector<vector<int>> dp(m,vector<int> (n,-1));
       
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++)
            {
              if(i==0 && j == 0)
                  dp[i][j] = 1;
              else
              {
                int down = 0, right = 0;
                if(i > 0)
                 down = dp[i-1][j];
                if(j > 0)
                 right = dp[i][j-1];
                 dp[i][j] = down + right;
              }
            }
        }
        return dp[m-1][n-1];
        }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return tabulation(m,n);
    }
};