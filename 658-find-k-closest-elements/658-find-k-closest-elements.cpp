class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > minheap;
        vector<int> res;
        for(int i = 0 ; i < arr.size() ; i++)
            minheap.push({abs(arr[i]-x),arr[i]});
        
        while(k--)
        {
            res.push_back(minheap.top().second);
            minheap.pop();
        }
        sort(res.begin(),res.end());
        return res;
    }
};