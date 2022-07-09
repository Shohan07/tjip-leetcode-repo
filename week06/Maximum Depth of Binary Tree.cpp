//TC : O(N) where N is the total nodes of the tree
//SC : O(H)  where H is the max height of the tree
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return max((maxDepth(root->left) + 1), (maxDepth(root->right) + 1));
    }
};or<int>>ans;
        dfs(root, 0, ans);
        return ans;
    }
};