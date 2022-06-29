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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) 
            return head;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
         ListNode *prev  = dummy;
        
       
        while(head && head->next)
        {
            //initialize two pointers
            ListNode* first = head;
            ListNode* second = head->next;
            
            //swapping takes place
            prev->next = second;
            first->next = second->next;
            second->next = first;
            
            //modifying prev and head
            head = first->next;
            prev = first;
        }
        return dummy->next;
    }
};