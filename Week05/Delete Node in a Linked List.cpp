//TC : O(1)
//SC : O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* nextNode;
        nextNode = node -> next;
        *node = *nextNode;
        delete nextNode;
    }
};