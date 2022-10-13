class Solution {
private:
int tabulation(vector<int> &arr)
{
  int n = arr.size();
  int maxi = 0,lastIndex = 0;
  vector<int> dp(n,1) , count(n,1); //dp represent max LIS till ith element
   for(int i = 0 ; i < n ; i++){    // and count arr represent total subsequence till ith element
    for(int prev = 0 ; prev < i ; prev++)
    {
      if(arr[prev] < arr[i] && 1 + dp[prev] > dp[i]){
        dp[i] =  1+dp[prev];
        count[i] = count[prev];
          
      }else if(arr[prev] < arr[i] && 1 + dp[prev] == dp[i]){
           count[i] += count[prev];
      }
    }
    maxi = max(maxi,dp[i]);
   }
  
   int ans = 0;
   for(int i = 0 ; i < n ; i++){
     if(maxi == dp[i])
         ans += count[i];
     }
   return ans;
}
public:
    int findNumberOfLIS(vector<int>& nums) {
        return tabulation(nums);
    }
};