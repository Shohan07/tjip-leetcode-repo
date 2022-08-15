//TC : O(n) where n = nums.size()
//SC : O(n)
class Solution {
public:
    vector<int> cache;
    
    int maxRob(int pos, vector<int> &nums)
    {
        if(pos >= nums.size())return 0;
        if(cache[pos] != -1)return cache[pos];
        
        int maxGain = max(maxRob(pos + 1, nums), nums[pos] + maxRob(pos + 2, nums));
        return cache[pos] = maxGain;
    }
    
    int rob(vector<int>& nums) {
        cache.clear();
        cache.resize(nums.size(), -1);
        return maxRob(0, nums);
    }
};

...................................................................
    
//TC : O(n) 
//SC : O(1)

class Solution {
public:
    int rob(vector<int>& nums) {
        int cur = 0, prev1 = 0, prev2 = 0;
        
        for(auto n : nums){
            cur = max(prev1, n + prev2);
            prev2 = prev1;
            prev1 = cur;
        }
        return cur;
    }
};