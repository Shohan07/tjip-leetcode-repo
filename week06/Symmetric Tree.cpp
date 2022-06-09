//TC : O(H) where H is the height of the tree
//SC : O(H) where H is the height of the tre which used for recursion stack
class Solution {
private:
    bool isSymmetric(TreeNode* l, TreeNode* r)
    {
        if(l == NULL && r == NULL) return true;
        
        if(l == NULL || r == NULL) return false;
        return ((l->val == r->val) && isSymmetric(l->left, r->right) && isSymmetric(l->right, r->left));
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isSymmetric(root->left, root->right);
    }
};