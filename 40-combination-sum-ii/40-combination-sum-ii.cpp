class Solution {
private:
  void solve(vector<int> &arr, int index,int target ,vector<int> &temp, vector<vector<int>> &ans)
  {
      if(target == 0){ // result condition
         ans.push_back(temp);
          return;
      }
      else if (target < 0 || index >= arr.size()) return ; // base condition
        else{
          for(int j = index ; j < arr.size() ; j++)
          {
              if(j!=index && arr[j] == arr[j-1]) continue; //to avoid duplicate or reuse of same variable;
              temp.push_back(arr[j]);
              solve(arr,j+1,target - arr[j],temp,ans);
              temp.pop_back();
          }
       }
  }
public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
       sort(arr.begin(),arr.end());
        vector<vector<int>> res;
        vector<int> temp;
        
        solve(arr,0,target,temp,res);
        return res;
    }
};