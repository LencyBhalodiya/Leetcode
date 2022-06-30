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
ListNode* reverseLL(ListNode * head,ListNode *right)
{
    ListNode *curr = head;
    ListNode *prev = NULL;
    while(prev!=right)
    {
      ListNode * next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
 return prev;
}
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head or !head->next or left == right)
            return head;
        
        ListNode* temp = new ListNode(-1); //create dummy node and join before head
        ListNode*prev = temp;
        temp->next = head;
      
        ListNode* low = head,*high = head,*highnxt = head->next;
        
        for(int i = 0 ; i < left-1 ; i++) //assign pointer to previous of left node and left node
        {
            prev = prev->next;
            low = low->next;
        } 
        for(int i = 1 ; i < right ; i++)
        {//assign pointer to right node and next of right node
            high = high->next;
            highnxt = highnxt->next;
        }
           prev->next = NULL;
           high->next = NULL;
        //reverser the linklist
        ListNode *ans = reverseLL(low,high);
        prev->next = ans; //join the null pointer
        low->next = highnxt;
        
        return temp->next;
    }
};