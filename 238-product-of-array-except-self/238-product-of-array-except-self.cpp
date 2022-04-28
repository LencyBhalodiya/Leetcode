class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n,1);
        vector<int> prefix,suffix(n,1);
        
        int product =1, product2 = 1, k = n-1;
        
       for(int i =0 ; i < n ; i++)
       {
          product*=arr[i]; // compute prefix product
           prefix.push_back(product);
           
           product2 *= arr[k]; // compute suffix product
           suffix[k] = product2;
           k--;
       }
        
        res[0] = suffix[1]; //first position is the product of suffix * from nth array to 1
        res[n-1] = prefix[n-2]; // last position is the prodict of array from 1 to n-2
        
        for(int i = 1 ; i < n-1 ; i++)
            res[i] = prefix[i-1] * suffix[i+1];
        
        
        return res;
    }
};