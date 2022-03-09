class Solution {
private:
void solve(vector<vector<int>> &res, vector<int> &arr,int index)
{
    if(index == arr.size())
    {
         res.push_back(arr); 
        return;
    }
    for(int i = index ; i < arr.size(); i++)
    {
        swap(arr[i],arr[index]);
         solve(res,arr,index+1);
        swap(arr[i],arr[index]);
    }
}
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int index = 0;
        solve(res,nums,index);
        return res;
    }
};