class Solution {
private:
int solve(vector<int> &arr, int n , int target, int index, vector<int> &dp)
{
    if(target == 0) return 1;
    if(n < 0 || target < 0) return 0;
    
   if(dp[target]!= -1) return dp[target];
    
    int ans = 0;
    
    for(int i = index ; i < n ; i++)
        ans += solve(arr,n,target - arr[i],index,dp);
    
    dp[target] = ans;
    return dp[target];
}

public: 
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1,-1);
         return solve(nums,n,target,0,dp);
    }
};