class Solution {
private:
   int solve(vector<int> &arr , vector<int> & cost , int index , int valid,vector<vector<int>> &dp)
   {
       if(index >= arr.size())
           return 0;
       
       if(dp[index][valid] != -1) 
           return dp[index][valid];
       
       if(arr[index] <= valid)
         return dp[index][valid] = solve(arr,cost,index+1,valid,dp);
       else{
       int op1 = solve(arr,cost,index+1,arr[index],dp) + cost[0];
       int op2 = solve(arr,cost,index+1,arr[index] + 6,dp) + cost[1];
       int op3 = solve(arr,cost,index+1,arr[index] + 29,dp) + cost[2];
           
       return  dp[index][valid] = min(op1,min(op2,op3));
       }
   }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<int>> dp(days.size(),vector<int> (days[days.size()-1]+ 30,-1));
        return solve(days,costs,0,0,dp);
    }
};