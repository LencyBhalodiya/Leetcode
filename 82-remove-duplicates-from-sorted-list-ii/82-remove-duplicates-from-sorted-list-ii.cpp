/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* ans = new ListNode(-1);
        ListNode *res = ans;
        ListNode * curr = head;
        vector<int> arr;
        unordered_map<int,int> mp;
        
        while(curr!=NULL)
        {
            mp[curr->val]++;
            curr = curr->next;
        }
        for(auto x : mp)
        {
            if(x.second == 1)
                arr.push_back(x.first);
        }
        sort(arr.begin(),arr.end());
        for(int i = 0 ; i < arr.size() ; i++)
         {
            ans->next = new ListNode(arr[i]);
            ans = ans->next;
         }
        return res->next;
    }
};