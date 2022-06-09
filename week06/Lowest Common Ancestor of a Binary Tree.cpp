//TC : O(N),Where N, total number of nodes in the tree
//SC : O(H) Where H, total height of tree for recursion stack
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root -> val == p -> val || root -> val == q -> val) return root;
        
        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);
        
        if(left && right)return root;
        return left ? left : right;
    }
};