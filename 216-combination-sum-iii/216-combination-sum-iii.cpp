class Solution {
private:
  void solve(int index,int k , int target , vector<int> &temp, vector<vector<int>> &ans)
  {
      if(k <= temp.size()){ //base condtion
          if(target == 0)
              ans.push_back(temp);
          return;
      }
      if(target < 0) return; //terminate condition
      
      for(int j = index ; j <= 9; j++) 
      {
          temp.push_back(j);
          solve(j+1,k,target - j,temp,ans); 
          temp.pop_back();
      }
  }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(1,k,n,temp,ans);
        return ans;
    }
};