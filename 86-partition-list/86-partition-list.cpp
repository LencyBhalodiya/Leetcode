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
    ListNode* partition(ListNode* head, int x) {
        ListNode* p1 = new ListNode(-1);
         ListNode* p2 = new ListNode(-1);
        ListNode *curr1 = p1, *curr2 = p2;
        //create two dummy linklist
        while(head)
        {
          if(head->val < x) // add numbers less than x to linklist1
          {
             p1->next = head;
              p1 = p1->next;
          }else{
              p2->next = head; //add number more than x to lnklst2
              p2 = p2->next;
          }
            head = head->next;
        }
        p1->next = curr2->next;  //connect both the linklist
         p2->next = NULL;

        
        return curr1->next;
    }
};