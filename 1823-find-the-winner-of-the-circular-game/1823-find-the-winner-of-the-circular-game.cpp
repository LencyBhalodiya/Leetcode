class Solution {
public:
    int findTheWinner(int n, int k) {
        if(k == 1) return n;
        queue<int> q;
        for(int i = 1 ; i <=n ; i++) //insert 1 to n element;
            q.push(i);
        
        for(int i = 0 ; i < n-1 ; i++) //games will be played  n-1 times round
        {
            int counter = k;
            while(counter!=1)
            {
                int val = q.front(); //value which is lesser than k push back val at back of queue 
                 q.pop();
                q.push(val);
                counter--;
            }
            q.pop(); //pop the kth element
        }
        
        return q.front();
    }
};