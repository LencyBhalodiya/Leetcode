class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int n=nums.size();
        for(int c=0; c<n-1; c++)
        {
            for(int i=0; i<n-c-1; i++)
            {
                nums[i] += nums[i+1]; //sums
                nums[i] = nums[i]%10; // copy sum to ith
            }
        }
        return nums[0];
    }
};