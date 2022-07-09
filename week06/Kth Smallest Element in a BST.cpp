//TC : O(h+k) where h is the height of binary tree
//SC : O(h) where h is the height of binary tree used for  stack memory


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        while(1){
            while(root){
                s.push(root);
                root = root -> left;
            }
            root = s.top();
            s.pop();
            if(--k == 0)return root -> val;
            root = root -> right;
        }
    }
};