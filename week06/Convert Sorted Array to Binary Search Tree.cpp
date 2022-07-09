//TC : O(N)
//SC : O(log(N))
class Solution {
private: 
    TreeNode* toBST(vector<int>&nums, int low, int high){
        if(low > high)return NULL;
        
            int mid = low + (high - low) / 2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = toBST(nums, low, mid-1);
            root->right = toBST(nums, mid+1, high);
            return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return toBST(nums, 0, nums.size()-1);
    }
};
