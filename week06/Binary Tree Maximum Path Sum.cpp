//TC : O(n) where n = number of nodes
//SC : O(h) where h is the height of binary tree used for resursion stack memory


class Solution {
public:
    int dfs(TreeNode* root, int &mxSum){
        if(!root)return 0;
        
        int lMax = dfs(root -> left, mxSum);
        int rMax = dfs(root -> right, mxSum);
        lMax = max(lMax, 0);
        rMax = max(rMax, 0);
        
        mxSum = max(mxSum, lMax + rMax + root -> val);
        return root -> val + max(lMax, rMax);
    }
    
    int maxPathSum(TreeNode* root) {
        int mxSum = INT_MIN;
        dfs(root, mxSum);
        return mxSum;
    }
};