class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        if(target > arr[arr.size()-1]) return arr.size();
        if(target < arr[0]) return 0;
        int low = 0,high = arr.size();
        int res = 0;
        while(low<=high)
        {
            int mid = low + (high - low)/2;
            if(arr[mid] == target)
                return mid;
            else if (arr[mid] > target){
                high = mid-1;
             }else{
                low = mid+1;
            }
        }
        
        return low;    
    }
};