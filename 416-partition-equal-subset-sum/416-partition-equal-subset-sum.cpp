class Solution {
private:
int solveUtil(vector<int> &arr, int  n , int sum,vector<vector<int>> &dp)
{
    if(sum == 0) return true;
    if(n == 0){
     if(sum == arr[0]) return true;
        return false;
    }
    if(dp[n][sum] != -1)
        return dp[n][sum];
    
  int notTake = solveUtil(arr, n-1 , sum,dp);
  int take = false;
  if(arr[n] <= sum)
   take = solveUtil(arr,n-1, sum - arr[n],dp);
    
  int ans = take || notTake;
    
  return dp[n][sum] = ans;
}
private:
int solve(vector<int> arr, int n )
{
  int sum = 0;
  for(auto i : arr)
      sum += i; 
    
    if(sum % 2 != 0) return false;
    vector<vector<int>> dp(n,vector<int>((sum/2)+1,-1));
    return solveUtil(arr,n-1 ,sum/2,dp);
}
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(solve(nums,n) == 1)
            return true;
        
        return false;
    }
};