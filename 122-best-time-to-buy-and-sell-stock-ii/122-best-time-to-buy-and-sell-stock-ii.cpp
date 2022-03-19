class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int res = 0;
        if(arr.size() == 1) return res;
        for(int i = 0 ; i < arr.size()-1 ; i++)
        {
            if(arr[i+1] > arr[i] )
                res += arr[i+1]-arr[i];
        }
        return res;
    }
};