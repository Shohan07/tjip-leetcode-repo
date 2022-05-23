//TC: O(n)
//SC: O(n)
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> mp;
        vector<TreeNode*> ans;
        helper(root, mp, ans);
        return ans;
    }
    string helper(TreeNode* root, unordered_map<string, int>&mp, vector<TreeNode*>& ans){
        if(!root) return "$";
        string s = to_string(root->val) + "," + helper(root->left, mp, ans) + "," + helper(root->right, mp, ans);
        cout << s << "\n";
        mp[s]++;
        if(mp[s] == 2)ans.push_back(root);
        return s;
    }
};