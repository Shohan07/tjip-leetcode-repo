//TC : O(N)Where N is the total number if nodes
//SC : O(N) 
class Solution {
public:
    TreeNode* build(vector<int>& preorder, unordered_map<int, int>& inMap, int& rootIdx, int left, int right) {
        if (left > right) return NULL;
        
        TreeNode* newNode = new TreeNode(preorder[rootIdx]);
        int inMid = inMap[preorder[rootIdx]];
        rootIdx++;
        newNode->left = build(preorder, inMap, rootIdx, left, inMid-1);
        newNode->right = build(preorder, inMap, rootIdx, inMid+1, right);
        return newNode;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for(int i = 0; i < inorder.size(); i++){
            inMap[inorder[i]] = i;
        }
        int rootIdx = 0;
        return build(preorder, inMap, rootIdx, 0, inorder.size()-1);
    }
    
};