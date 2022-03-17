class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        //transpose of the matrix
        for(int i = 0 ; i < arr[0].size(); i++)
        {
            for(int j = i+1 ; j < arr[0].size() ; j++)
            {
                swap(arr[i][j],arr[j][i]);
            }
        }
        //reverse of the matrix
        for(int i = 0 ; i < arr[0].size() ; i++){
         int left = 0 ,right = arr[0].size()-1; // two pointer approach
            for(int j = 0 ; j < arr[0].size()-1 ; j++)
            {
                 if(left<=right){
                  swap(arr[i][left],arr[i][right]);
                      left++;
                      right--;
                 }
            }
        }
        
    }
};