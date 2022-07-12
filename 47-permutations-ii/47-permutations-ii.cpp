class Solution {
private:
 void solve(vector<int> &arr,int i,vector<vector<int>> &ans )
 {
    if(i == arr.size()){
        ans.push_back(arr);
        return;
    }
     unordered_map<int,bool> mp ; 
     for(int j = i ; j < arr.size() ; j++)
     {
       if(mp[arr[j]]) continue; // keep track of used element 
            mp[arr[j]] = true; // basically idea is not to swap two identical element
         
         swap(arr[i],arr[j]);
         solve(arr,i+1,ans);
         swap(arr[i],arr[j]);
     }
     return;
 }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        solve(nums,0,ans);
        return ans;
    }
};