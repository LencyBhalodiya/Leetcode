class Solution {
 
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
       int start = 0,end = 0,sum = 0, res = 0;
        int n = arr.size();
        while(end < n){
            sum += arr[end]; //add elements
            
            if(end - start + 1 == k){ // if window size equal to k
                if(sum/k >= threshold)
                    res++;
                sum -= arr[start++]; // remove previous elements
            }
            end++;
        }
        return res;
    }
};