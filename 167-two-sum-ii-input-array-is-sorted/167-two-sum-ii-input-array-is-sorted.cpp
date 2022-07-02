class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int low = 0 , high = arr.size()-1;
        vector<int> res;
        while(low < high)
        {
          if(arr[low]+arr[high] == target)
          {
              res.push_back(low+1);
              res.push_back(high+1);
              return res;
          }else if(arr[low] + arr[high] < target)
              low++;
            else
                high--;
        }
        return res;
    }
};