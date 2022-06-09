//TC : O(N) total nodes of the tree
//SC : O(N) total nodes size for output storing
class Solution {
public:
    int getHeight(vector<vector<int>>& ans, TreeNode* root){
        if(!root){
            return -1;
        }
        int leftHeight = getHeight(ans, root -> left);
        int rightHeight = getHeight(ans, root -> right);
        
        int currHeight = max(leftHeight, rightHeight) + 1;
        
        if(ans.size() == currHeight){
            ans.push_back({});
        }
        
        ans[currHeight].push_back(root -> val);
        
        return currHeight;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        getHeight(ans, root);
        return ans;
    }
};