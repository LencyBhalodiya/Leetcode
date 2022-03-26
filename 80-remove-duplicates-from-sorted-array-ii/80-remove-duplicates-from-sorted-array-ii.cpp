class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int i = 0, res = 1, count = 1;
        if(arr.size() < 2) return arr.size();
        
        while(i < arr.size()-1)
        {
            if(arr[i] == arr[i+1])
            {
                count++;
                if(count <= 2){
                    arr[res] = arr[i];
                    res++;
                }
            }
            else{
                arr[res] = arr[i+1];
                count = 1;
                res++;
            }
        i++;
        }
        return res;
    }
};