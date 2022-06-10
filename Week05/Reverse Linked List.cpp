//TC : O(N)
//SC : O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *next;
        while(head != NULL){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};