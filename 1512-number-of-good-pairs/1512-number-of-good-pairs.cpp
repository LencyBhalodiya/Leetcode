class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int arr[102] = {0};
        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i++)
            arr[nums[i]]++;   
        
        for(int i = 0 ; i < 102; i++)
        {
            if(arr[i] != 0)
            ans = ans + (arr[i]*(arr[i]-1))/2;
        }
        
        return ans;
    }
};