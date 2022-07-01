class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size(),low = 0 ;
        if(n == 1) return arr[0];
        int high = n-1;
        int res = INT_MAX;
        while(low<=high)
        {
          int mid = (low + high)/2;
            
            if(arr[mid] > arr[low])
            {
                res = min(res,arr[low]);
                low = mid+1;
            }else
            {
                if(arr[mid] > arr[high]){
                    res = min(arr[high],res);
                   low = high+1;
                }else{
                    res = min(arr[mid],res);
                    high = mid-1;
                }
            }
        }
        return res;
    }
};