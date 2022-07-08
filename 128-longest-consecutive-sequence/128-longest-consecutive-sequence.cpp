class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> s;
        int res= 0;
        for(auto i : arr)
            s.insert(i); //insert array elements in unordered set

        for(int i = 0 ; i < arr.size() ; i++)
        {
          if(s.find(arr[i]-1) == s.end()) //element should be the starting element of series
          {
              int j = arr[i];
              while(s.find(j) != s.end()) // count by adding 1 to j if it is present in set
                  j++;
              
              res = max(res,j-arr[i]); // store the maximum length
          }
        }
        return res;
    }  
};