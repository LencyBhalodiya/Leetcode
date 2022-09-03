class Solution {
private:
    int solve(vector<int> &arr,int n , vector<int> &dp)
    {
      dp[0] = arr[0];
        for(int i = 1 ; i < n ; i++)
        {
          int take = arr[i];
          if(i > 1)
            take += dp[i-2]; // pick element and add n-2 element
          int noTake = 0 + dp[i-1]; // move index by 1 but don't add sum
          dp[i] = max(take,noTake); // take max of both
        }
      return dp[n-1];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if( n == 1) return nums[0];
        vector<int> v1(nums.begin()+1,nums.end()); // exclude 1st element
        vector<int> v2(nums.begin(),nums.end()-1); // exclude last element to avoid adjacent
        //since it is circular we need to avoid 1 and last element since their are adjacent
        vector<int> dp(n,-1);
        return max(solve(v1,v1.size(),dp),solve(v2,v2.size(),dp));
    }
};