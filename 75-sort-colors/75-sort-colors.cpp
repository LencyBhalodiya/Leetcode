class Solution {
public:
    void sortColors(vector<int>& arr) {
     int first = 0;
    int end = arr.size()-1;
    int second = 0;

    while(second<=end){
        if(arr[second] == 0)
        {
            swap(arr[second] , arr[first]);
            first++;
            second++;
        }else if(arr[second] == 1)
         {
             second++;
         }else{
             swap(arr[second],arr[end]);
             end--;
         }
    }
        
    }
};