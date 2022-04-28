class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& arr) {
        int n = arr.size();
        vector<int> res;
        for(int i = 0 ; i < n ; i++)
        {
           int index = abs(arr[i])-1;
            if(arr[index] > 0)
                arr[index] = -arr[index];
            // else
            //     arr[index] = arr[index];
        }
        
        for(int i = 0 ; i < n ; i++)
            if(arr[i] > 0)
             res.push_back(i+1);
        
        return res;
    }
};