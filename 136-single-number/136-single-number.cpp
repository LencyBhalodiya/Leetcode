class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int res = 0;
        
        for(int i = 0 ; i < arr.size() ; i++)
            res = res^arr[i]; //xor with two same number gets cancelled out
        
        return res;
    }
};