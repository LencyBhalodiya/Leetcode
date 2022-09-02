class Solution {
private:
int solve(int n , vector<int> nums,vector<int> &dp)
{
    if(n == 0) return nums[n];
    if(n < 0) return 0;
    if(dp[n]!= -1)
        return dp[n];
    int left = nums[n] + solve(n-2,nums,dp) ; // skip adjacent
    int right = solve(n-1,nums,dp) + 0; // move to next without adding adjacent
        
    return dp[n] = max(left,right);
}
int tabulation(int n , vector<int> arr,vector<int> &dp)
{
    dp[0] = arr[0];
    
    for(int i = 1 ; i < arr.size(); i++)
    {
      int take = arr[i];
        if(i > 1)
         take += dp[i-2];
      int notTake = 0+dp[i-1];
          
      dp[i] = max(take,notTake);
    }
    return dp[n];
}
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return tabulation(n-1,nums,dp);
    }
};