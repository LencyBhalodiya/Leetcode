class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char,int> mp;
        for(int i = 0 ; i < s.length() ; i++)
            mp[s[i]]++; // store char count in mp;
         
        priority_queue<pair<int,char>> p;
        
        for(auto  x : mp) // push map char count in max-heap order
         p.push({x.second,x.first});
        
        while(!p.empty())
        {
            int count = p.top().first; //take count of char 
            while(count!=0){
                ans += p.top().second; //push them count  times into ans string
                count--;
            }
            p.pop();
        }
        return ans;
    }
};