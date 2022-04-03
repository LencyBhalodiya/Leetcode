class Solution {
public:
    int xorOperation(int n, int start) {
        int res = 0;
        int count = start;
        for(int i = 0 ; i < n ; i++)
        {
            res = res^count;
            count+=2;
        }
        return res;
    }
};