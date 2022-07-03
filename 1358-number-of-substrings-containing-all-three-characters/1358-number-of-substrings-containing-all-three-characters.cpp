class Solution {
public:
    int numberOfSubstrings(string s) {
         int i = 0,j = 0;
        int n = s.size(), ans=0;
        vector<int> arr(3,0); //initialize array to 0
        
        while(i<n)
        {
            arr[s[i]-'a']++; //add the latest element to window
            while(arr[0]>0 and arr[1]>0 and arr[2]>0)
            {
                arr[s[j]-'a']--; //remove the 1st element of window
                j++; //slide the window
                ans+=n-i; // add n-(window length) to answer
            }
            i++;
        }
        return ans;
    }
};