class Solution {
// private:
// int recursion(vector<int> arr, int index = 0, int buy = 1, int n )
// {
//      if(idx >= n) return 0;
//     long profit  = 0;
    
//     if(buy) // buy and move or not buy and move
//     profit = max(-arr[idx] + memoization(arr,idx+1,0,n,dp), 0 + memoization(arr,idx+1,1,n,dp)); 
//     else //sell and move 2 step to skip the next indx
//     profit = max(arr[idx] + memoization(arr,idx+2,1,n,dp), 0 + memoization(arr,idx+1,0,n,dp));
    
//    return profit;
// }
private:
int memoization(vector<int> arr , int idx , int buy,int n, vector<vector<int>> &dp )
{
    if(idx >= n) return 0;
    long profit  = 0;
    if(dp[idx][buy] != -1)
     return dp[idx][buy];
    if(buy) // buy and move or not buy and move
    profit = max(-arr[idx] + memoization(arr,idx+1,0,n,dp), 0 + memoization(arr,idx+1,1,n,dp)); 
    else // sell and move or not sell and move
    profit = max(arr[idx] + memoization(arr,idx+2,1,n,dp), 0 + memoization(arr,idx+1,0,n,dp));
   
   return dp[idx][buy] = profit;
}
int tabulation(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<long>> dp(n+2,vector<long> (2,0));
    dp[n][0] = dp[n][1] = 0;
    for(int i = n-1 ; i >= 0; i--)
    {
        for(int buy = 0 ; buy <= 1 ; buy++)
        {
          int profit = 0;
           if(buy) // buy and move or not buy and move
           profit = max(-arr[i] + dp[i+1][0], dp[i+1][1]); 
            else // sell and move 2 step or not sell and move 1 step
            profit = max(arr[i] + dp[i+2][1], dp[i+1][0]);

            dp[i][buy] = profit;
        }
    }
    return dp[0][1];
}
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        // return tabulation(prices);
        return memoization(prices,0,1,n,dp);
    }
};