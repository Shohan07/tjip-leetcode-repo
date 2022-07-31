// TC : O(W * HlogH) here, W is the width of the tree(level when you travarse in vertical order) H is the heght of the tree
// SC : O(N) N = number of the nodes of the tree
class Solution {
public:
    map<int, vector<pair<int, pair<int, int>>>> nodes;
    int rank;
    
    void dfs(TreeNode* u, int ort = 0, int level = 0)
    {
        if(u == NULL)return;
        nodes[ort].push_back({level, {rank++, u->val}});
        dfs(u->left, ort - 1, level + 1);
        dfs(u->right, ort + 1, level + 1);
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        nodes.clear();
        rank = 0;
        dfs(root);
        vector<vector<int>> vertOrder;
        for(auto &it : nodes)
        {
            auto nodelist = it.second;
            sort(nodelist.begin(), nodelist.end());
            vector<int> levelNodes;
            for(auto node : nodelist)
            {
                levelNodes.push_back(node.second.second);
            }
            vertOrder.push_back(levelNodes);
        }
        return vertOrder;
    }
};
