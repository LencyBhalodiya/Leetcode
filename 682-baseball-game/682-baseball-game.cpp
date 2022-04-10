class Solution {
public:
    int calPoints(vector<string>& ops) {
        int ans = 0;
        vector<int> arr;
      
        for(int i = 0 ; i < ops.size() ; i++)
        {
            if(ops[i] == "D")
            {
              arr.push_back(arr[arr.size()-1]*2);
            }else if(ops[i] == "+"){
                arr.push_back(arr[arr.size()-1] + arr[arr.size()-2]);
            }else if (ops[i] == "C"){
                arr.pop_back();
            }else{
                int c = stoi(ops[i]);
                arr.push_back(c);
            }
        }
        for(int i : arr)
        ans += i;
      return ans;
    }
};