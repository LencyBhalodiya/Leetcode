class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> medians;
        int n = nums.size();
        unordered_map<int,int> mp; // for late deletion
        priority_queue<int> maxh; // max heap for lower half
        priority_queue<int, vector<int>, greater<int>> minh; // min heap for upper half
        
        for(int i=0;i<k;i++) {
            maxh.push(nums[i]);
        }
         for(int i=0;i<(k/2);i++) {
            minh.push(maxh.top());
            maxh.pop();
        }
        // always try to main the middle element on the top of maxh heap
        // if we have even elements in both the heaps, median is avg of top of both heaps
        for(int i=k;i<n;i++) {
            if(k&1) { // if k is odd, we will have median on the top of maxheap
                medians.push_back(maxh.top()*1.0);
            }
            else {
                medians.push_back(((double)maxh.top()+(double)minh.top())/2);
            }
            int prev =nums[i-k], curr =nums[i]; // 
            // we need to remove p and add q;
            // we will delete p when it will come on the top
            // to keep track we will maintain map
            int balance = 0; // keep heaps in balance, for correct ans
            // we decrese balance when remove elements from maxh, so basically if balance<0 it means maxheap has lesser elemets the minheap
            // removing prev or adding prev to map to delete it later
            if(prev<=maxh.top()) { // prev is in maxheap
                balance--;
                if(prev==maxh.top())
                    maxh.pop();
                else
                    mp[prev]++;
            }
            else { // prev is min heap
                balance++;
                if(prev == minh.top())
                    minh.pop();
                else
                    mp[prev]++;
            }
            
            // inserting curr to the right heap
            if(!maxh.empty() and curr<=maxh.top()) { // pushing curr to maxheap
                maxh.push(curr);
                balance++;
            }
            else { // pushing curr to minheap
                minh.push(curr);
                balance--;
            }
            
            // balancing both the heaps
            if(balance<0) {
                maxh.push(minh.top());
                minh.pop();
            }
            else if(balance>0) {
                minh.push(maxh.top());
                maxh.pop();
            }
            
            // removing top elements if they exist in our map(late deletion)
            while(!maxh.empty() and mp[maxh.top()]) {
                mp[maxh.top()]--;
                maxh.pop();
            }
            while(!minh.empty() and mp[minh.top()]) {
                mp[minh.top()]--;
                minh.pop();
            }
        }
        if(k&1) {
            medians.push_back(maxh.top()*1.0);
        }
        else {
            medians.push_back(((double)maxh.top()+(double)minh.top())/2.0);
        }
        return medians;
    }
};