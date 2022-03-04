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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        vector<int> arr;
        ListNode * curr = head;
        //store elements int array and sort the array
        while(curr!= NULL)
        {
            arr.push_back(curr->val);
            curr = curr->next;
        }
        
        sort(arr.begin(),arr.end());
        
        ListNode *ans = new ListNode(arr[0]); //create new linklist
        ListNode* res = ans;
         // add item from sorted array to new linklist
        for(int i = 1 ;  i < arr.size() ; i++)
        {
            ans->next = new ListNode(arr[i]);
            ans = ans->next;
        }
        return res;
    }
};