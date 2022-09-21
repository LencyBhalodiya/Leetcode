class Solution {
private:
int solve(int i , int j,string s, string t)
{
   if ( j < 0 )
   return 1;
 if ( i < 0 )
    return 0;
 if (  s[i] == t[j] ) {
          return solve ( i-1 , j - 1, s, t ) + solve( i - 1 , j, s , t ); // move ith index to check for other alphabet
}
            return solve( i - 1 , j , s , t );

}
int tabulation(string s , string t)
{
  int n = s.size();
  int m = t.size();
    vector<vector<double>> dp(n+1 , vector<double> (m+1, 0));
    
    for(int i = 0 ; i <= n ; i++)
        dp[i][0] = 1;
    
    for(int i = 1 ; i<=n ; i++){
        for(int j = 1; j <= m ; j++){
           if(s[i-1] == t[j-1])
             dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            else
             dp[i][j] = dp[i-1][j];
        }
    }
    return (int)dp[n][m];
}
public:
    int numDistinct(string s, string t) {
        int i = s.length();
        int j = t.length();
        
        return tabulation(s,t);
    }
};