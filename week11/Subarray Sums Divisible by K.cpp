// TC : O(n) n = nums size
// SC : O(k)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> seenPrefixSumModK(k + 1, 0);
        seenPrefixSumModK[0] = 1;
        int subarrCount = 0, preSum = 0;
        
        for(auto &num : nums)
        {
            preSum += num;
            while(preSum < 0)preSum += k;
            preSum %= k;
            
            subarrCount += seenPrefixSumModK[preSum];
            seenPrefixSumModK[preSum]++;
        }
        return subarrCount;
    }
};