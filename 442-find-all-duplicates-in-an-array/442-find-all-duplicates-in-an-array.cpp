class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int> res;
     if(arr.size() < 2) return res ;

        int n  =arr.size();
        
        for(int i = 0 ; i < n ; i++)
        {
           int index = abs(arr[i])-1; // find element no as index number
            if(arr[index] > 0)
                arr[index] = -arr[index];
            else
                res.push_back(abs(arr[i]));
        }
        return res;
    }
};