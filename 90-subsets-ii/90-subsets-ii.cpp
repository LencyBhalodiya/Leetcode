class Solution {
private:
    void solve(vector<int> & nums, int index ,vector<int> &temp, vector<vector<int>> &ans)
    {
        ans.push_back(temp); //insert to ans 2d array
        
        for(int j = index ; j < nums.size() ; j++)
        {
            if(j > index && nums[j]==nums[j-1])
                continue;
            temp.push_back(nums[j]); //push element
            solve(nums,j+1,temp,ans);
            temp.pop_back(); //pop elemnt
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end()); // sort the array for comparing previous element
        solve(nums,0,temp,ans);
        return ans;
    }
};