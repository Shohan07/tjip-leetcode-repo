//TC : O(N)
//SC : O(1)
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        ListNode* head2 = slow -> next;
        slow -> next = NULL;
        
        ListNode* p = head;
        ListNode *q = NULL, *r = NULL;
        while(p){
            r = q;
            q = p;
            p = p -> next;
            q -> next = r;
        }
        head = q;
        
        int ans = 0;
        while(head){
            ans = max(head -> val + head2 ->val, ans);
            head = head -> next;
            head2 = head2 -> next;
        }
        return ans;
    }
};