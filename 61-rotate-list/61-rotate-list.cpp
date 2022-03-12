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
   ListNode* insideKth(ListNode* head, int k,int count)
   {
       //if node is greater than size of linklist 
       if(k > count){
           while(k > count)
               k = k-count;
       }
        ListNode* helpNode = head;
        ListNode *kthNode = head;
        ListNode * prev = head;
        ListNode *lastNode = head;
       //put one pointer a kth times a head
        for(int i = 0 ; i< k; i++){
            helpNode = helpNode->next;
            if(i != 0)
             lastNode = lastNode->next;
        }
        //traverse to get till kth time 
        while(helpNode!=NULL){
            helpNode  = helpNode->next;
            kthNode = kthNode->next;
            lastNode = lastNode->next;
        }
        lastNode->next = head;
        while(prev->next!=kthNode)
            prev = prev->next;
        prev->next = NULL;
       return kthNode; 
    }
   
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0) return head;
        if(head == NULL) return NULL;
        if(head->next == NULL ) return head;
        ListNode *currcount = head;
        int count = 1;
        //count total node
        while(currcount->next!= NULL)
        {
            currcount = currcount->next;
            count++;
        }
       return insideKth(head,k,count); 
    }
};