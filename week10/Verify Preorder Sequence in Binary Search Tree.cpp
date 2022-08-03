//TC : O(N) N = preorder size
//SC : O(N)
class Solution {
public:
    bool dfs(vector<int> &preorder, int &currIdx, int L, int R)
    {
        if(currIdx >= preorder.size()) return true;
        if (preorder[currIdx] < L || preorder[currIdx] > R) return false;
        int v = preorder[currIdx];
        currIdx++;
        bool c1 = dfs(preorder, currIdx, L, v);
        bool c2 = dfs(preorder, currIdx, v, R);
        
        return (c1 || c2);
    }
    
    bool verifyPreorder(vector<int>& preorder) {
        int currIdx = 0;
        return dfs(preorder, currIdx, INT_MIN, INT_MAX);
    }
};