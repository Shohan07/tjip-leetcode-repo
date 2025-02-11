//TC : O(n)
//SC : O(1)
class Solution {
public:
    Node* connect(Node* root) {
        Node *prev = root, *curr;
        while(prev){
            curr = prev;
            while(curr && curr->left){
                curr->left->next = curr->right;
                if(curr->next){
                    curr->right->next = curr->next->left;
                }
                 curr = curr->next;
            }
            prev = prev->left;
        }
        return root;
    }
};