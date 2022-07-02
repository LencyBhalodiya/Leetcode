class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int res = INT_MAX;
        int sum = 0;
        int left = 0 , right = 0;//assign two pointer at start
        
        while(right < arr.size())
        {
              sum+=arr[right++]; //add sum of array
            
            while(target <= sum)
            {
                res = min(res,right-left); //if sum becomes more than target then minus the previous starting element
                sum-=arr[left++];
            }
        }
        return res==INT_MAX?0:res;
    }
};