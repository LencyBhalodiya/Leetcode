class Solution {
private:
int solve(vector<int> &arr, int index , int target,vector<vector<int>> &dp)
{
    if(target == 0) return 0;
    if(target < 0 || index < 0)
        return 1e9;

    if(dp[index][target] != -1)
     return dp[index][target];

    int notTake = 0 + solve(arr,index-1,target,dp);
    int take = INT_MAX;
    if(target >= arr[index])
     take = 1 + solve(arr, index , target - arr[index],dp);

   return dp[index][target] =  min(take,notTake);
}
public:
    int help(vector<int>& coins, int amount, int n,vector<vector<int>>&h)
    {
        if(amount == 0) return 0;
        if(n < 0 || amount < 0) return INT_MAX-1;
        if(h[n][amount]!= -1) return h[n][amount];
        int one = help(coins,amount,n-1,h);
        int two = 1+help(coins,amount-coins[n],n,h);
        h[n][amount] = min(one,two);
        return h[n][amount];
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n ,vector<int>(amount+1,-1));
        // int ans = solve(coins,n-1,amount,dp);
        int ans = help(coins,amount,n-1,dp);
        if(ans >= 1e9)
            return -1;
        else
            return ans;
    }
};