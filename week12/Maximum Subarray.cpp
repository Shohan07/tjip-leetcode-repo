// TC : O(n) where n = nums size
// SC : O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, mxsum = nums[0];
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            mxsum = max(sum, mxsum);
            if(sum < 0) sum = 0;
        }
        return mxsum;
    }
};