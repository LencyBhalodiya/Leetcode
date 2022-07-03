class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
       int low = matrix[0][0],high = matrix[n-1][n-1];
        
        while(low < high)
        {
            int mid = low+(high-low)/2;
            int count = 0;
            
             for(int i = 0; i < n; i++){
              count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) -matrix[i].begin();
             }
            cout<<endl;
             if(count < k)
                low = mid + 1;
              else
                high = mid;
        }
        return low;
    }
};