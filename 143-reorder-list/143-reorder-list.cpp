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
private: 
    ListNode* reverseLL(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        while(curr)
        {
          ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
       
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return;
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast && fast->next) //find the mid point of LL
        {
          slow = slow->next;
           fast = fast->next->next;
        }
       ListNode*head2 = reverseLL(slow); // reverse linklist from midpoint
       ListNode *head1 = head;
        
        //create dummy Node
        ListNode*temp = new ListNode(-1);
        fast = temp;
        bool flag = true;
        while( head2 and head1)
        {
            if(flag == true)
            {
                fast->next = head1;
                head1 = head1->next;  
            }else{
                fast->next = head2;
                head2 = head2->next;  
            }
             fast = fast->next;
            flag = !flag;
        }
        head = temp->next;
    }
};