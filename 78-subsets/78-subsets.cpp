class Solution {
private:
 vector<vector<int>> ans;
private:
void solve(vector<int> &nums,vector<int> temp,int i)
{
    if(i == nums.size())
     ans.push_back(temp);
    else{
        temp.push_back(nums[i]); //add element to array
        solve(nums,temp,i+1);
        temp.pop_back(); //backtracking while returning
        
        solve(nums,temp,i+1); // don't add element to array
    }
   
}
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(nums,temp,0);
        return ans;
    }
};