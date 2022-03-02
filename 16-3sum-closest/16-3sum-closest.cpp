class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
      
        sort(arr.begin(),arr.end()); //sort the array
        int res = INT_MAX; 
        int ans;
        
        for(int i = 0 ; i < arr.size()-2 ; i++)
        {
            int j = i + 1 ; 
            int k = arr.size()-1;
            
            while(j < k)
            {  // two pointer approach and add ans with i element
                int sum = arr[i] + arr[j] + arr[k];
                
                if(sum < target)
                    j++;
                else if(sum > target)
                    k--;
                else
                 return sum;
                
                if(res > abs(sum-target)) // if difference is less than store sum to ans;
                {
                    ans = sum;
                    res = abs(sum-target);
                }
                
            }
        }
        return ans;
    }
};