//TC : O(N) where N is the total nodes of the tree
//SC : O(N)  where N is the total nodes of the tree
class Solution {
public:
    void dfs(TreeNode* root, int level, vector<vector<int>>& ans){
        if(root == NULL)return;
        if(ans.size() == level)ans.push_back({});
        if(level % 2 == 0){
            ans[level].push_back(root->val);
        }
        else{
            ans[level].insert(ans[level].begin(), root->val);
        }
        dfs(root->left, level + 1, ans);
        dfs(root->right, level + 1, ans);
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        dfs(root, 0, ans);
        return ans;
    }
};