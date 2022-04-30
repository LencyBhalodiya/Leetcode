class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& arr, int m, int n) {
        vector<vector<int>>  ans;
        vector<int> temp;
        int total_element = arr.size();
        int sizee = m*n;
        int j = n;
        int k = 0;
        if(total_element!=sizee)
            return ans;
        
      for(int i = 0 ; i < total_element; i++)
      {
          temp.push_back(arr[i]);
           j--;
          if(j == 0){
              ans.push_back(temp);
              temp.clear();
              j= n;
          }
      }
        
        return ans;
    }
};