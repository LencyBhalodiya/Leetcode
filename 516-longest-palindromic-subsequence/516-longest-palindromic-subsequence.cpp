class Solution {
private:
 int solve(string s, string s1, int i , int j,vector<vector<int>> &dp)
 {
     if(i < 0 || j < 0)
         return 0;
     
     if(dp[i][j] != -1)
         return dp[i][j];
     
     if(s[i] == s1[j]){
         return dp[i][j] = 1 + solve(s,s1,i-1,j-1,dp);
     }
     
     return dp[i][j] = max(solve(s,s1,i-1,j,dp),solve(s,s1,i,j-1,dp));
 }
int tabulation(string s ,string s1)
{
  int n = s.length();
  vector<vector<int>> dp(n+1,vector<int> (n+1 , -1));
    
  for(int i = 0 ; i <= n ; i++){
      dp[0][i] = 0;
      dp[i][0] = 0;
   }
    
  for(int i = 1 ; i <= n ; i++)
  {
     for(int j = 1; j <= n ; j++)
     {
        if(s[i-1] == s1[j-1]) // since startting from 1 index
         dp[i][j] = 1 + dp[i-1][j-1];
       else 
         dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
     }  
   }
    return dp[n][n];    
}
public:
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(),s2.end());
        int len = s.length();
        vector<vector<int>> dp(len+1,vector<int> (len +1 , -1)); // since  consider -1 index as 0 index (index forwarding)
        return tabulation(s,s2);
    }
};