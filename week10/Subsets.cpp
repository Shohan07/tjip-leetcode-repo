// TC : O(N * 2^N) Where N = number of elements
// SC :  O(N * 2^N)
class Solution {
public:
    bool checkBit(int n, int pos)
    {
        return (n & (1 << pos)) > 0;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int sz = nums.size();
        int numSubset = 1 << sz;
        vector<vector<int>> ans;
        for(int i = 0;  i < numSubset; i++)
        {
            vector<int> subset;
            for(int j = 0; j < nums.size(); j++)
            {
                if(checkBit(i, j)) subset.push_back(nums[j]);
            }
            ans.push_back(subset);
        }
        return ans;
    }
};