class Solution {
private:
int solve(vector<int> & arr, int index , int amount,vector<vector<int>> &dp)
{
    if(amount == 0) 
        return 1;
    if(amount < 0 || index < 0)
        return 0;
    if(dp[index][amount] != -1)
        return dp[index][amount];
    
    int notTake = solve(arr, index-1 , amount,dp);
    int take = solve(arr, index , amount - arr[index],dp);
    return dp[index][amount] = take + notTake;
}

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        int ans = solve(coins,n-1,amount,dp);
        return ans;
    }
};