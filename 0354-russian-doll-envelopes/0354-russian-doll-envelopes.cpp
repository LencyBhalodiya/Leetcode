class Solution {
private:
 static bool cmp(vector<int> &a , vector<int> &b) 
 {   if(a[0] == b[0]) return a[1] > b[1]; //if 0index is same them arrange 1st index in decreasing order
     return a[0] < b[0]; // arrange 0th index in increasing order
 }
public:
    int maxEnvelopes(vector<vector<int>>& arr) {
        int n = arr.size();
        if(n == 0) return 0;
        sort(arr.begin(),arr.end(),cmp); //sort the array
        
        vector<int> ans;
        ans.push_back(arr[0][1]); //intialize 1st element

        for(int i = 1; i < n ; i++)
        {
            int element = arr[i][1];
            if(element > ans.back()) //if larger than previous of ans than input
                ans.push_back(element);
            else
            {  // if not larger than place element at lowerbound of array
              int index = lower_bound(ans.begin(), ans.end(), element) - ans.begin();  
                ans[index] = element;
            }
        }
        return ans.size();
    }
};