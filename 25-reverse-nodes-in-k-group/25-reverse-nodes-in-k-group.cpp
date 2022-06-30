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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head or !head->next or k == 1)
             return head;
        
        ListNode *dummy = new ListNode(-1); //create dummy node and attach before head
        dummy->next = head;
        ListNode *prev = dummy ,*next = dummy, *curr = dummy;
        int count = 0;
        while(curr->next!=NULL) // count the total nodes
        {
            curr = curr->next;
            count++;
        }
        
        while(count >= k)
        {
           curr = prev->next;
           next = curr->next;
            
            for(int i = 1 ; i < k ; i++)
            { // same operation as reverse linklist part 2
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            prev = curr;
            count = count-k;
        }
        return dummy->next;
      
    }
};