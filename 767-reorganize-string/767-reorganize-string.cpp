class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        priority_queue<pair<int,char>> pq;
        unordered_map<int,int> mp;
        string res = "";
        
       
        for(int i = 0 ; i < s.length() ; i++) // store count in hashmap
            mp[s[i]]++;
        
        for(auto i : mp)
         pq.push(make_pair(i.second,i.first)); //insert in max heap
        
        while(pq.size() > 1){
          auto top1 = pq.top();
            pq.pop();
         auto top2 = pq.top();  //store two tops into the variable
            pq.pop();
            
            res+= top1.second; //store in string char top1 and top2 simuntaneously
            res+= top2.second;
            
            top1.first--;
            top2.first--;
        
            if(top1.first > 0) //if char frequency isn't equal to 0 then push again.
                pq.push(top1);
            if(top2.first > 0)
                pq.push(top2);
        }
        
        if(!pq.empty())
         {
            if(pq.top().first > 1)
                return "";
             else
                res += pq.top().second;
        }
            
            
        return res;
    }
};