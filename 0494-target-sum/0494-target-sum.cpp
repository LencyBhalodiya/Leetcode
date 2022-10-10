class Solution {
private:
int findWaysUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){

    if(ind == 0){
            if(target==0 && arr[0]==0)
                return 2;
            if(target==0 || target == arr[0])
                return 1;
            return 0;
    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = findWaysUtil(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = findWaysUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= notTaken + taken;
}
    
int findWays(vector<int> &arr, int target){
    int totSum = 0;
    int n = arr.size();
    for(int i=0; i<arr.size();i++){
        totSum += arr[i];
    }
    
    //Checking for edge cases
    if(totSum-target<0) return 0;
    if((totSum-target)%2==1) return 0;
    
    int s2 = (totSum-target)/2; // since s1 + s2 = totalsum and s1 - s2 = diff
                                // therefore diff - s2 -s2 = totalsum
    
    vector<vector<int>> dp(n,vector<int>(s2+1,-1));
    return findWaysUtil(n-1,s2,arr,dp);
}
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return findWays(nums,target);
    } 
};