class Solution {

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        int p = pow(2,nums.size());  
        for(int i = 0 ; i < p; i++)
        {
             temp.clear();
            for(int j = 0 ; j < nums.size() ; j++)
            {
                if((( 1<<j )& i)!=0)
                  temp.push_back(nums[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};