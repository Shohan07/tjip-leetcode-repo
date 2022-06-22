//TC : O(n) 
//SC : O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
       if(head == NULL || head->next == NULL){
           return 0;
       }
        
       ListNode *slow = head, *fast = head;
       
       while(fast->next != NULL && fast->next->next != NULL){
           fast = fast->next->next;
           slow = slow->next;
           if(fast == slow){
               return 1;
           }
       }
       return 0;
    }
};