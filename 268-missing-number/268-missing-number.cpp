class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        
        for(int i = 1 ; i < n+1; i++)
            res = res^i; //store range numbers in res
        
        for(int i = 0 ; i < n ; i++)
            res = res^nums[i]; //match with arr[i] and if equal to range numbers then it will cancel out 
        
        return res;
    }
};