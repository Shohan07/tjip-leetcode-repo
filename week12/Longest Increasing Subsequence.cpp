// TC : O(n log(n))
// SC: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            auto it = lower_bound(res.begin(), res.end(), nums[i]);
            if(it == res.end())res.push_back(nums[i]);//nums[i] > all element of res
            
            else *it = nums[i];
        }
        return res.size();
    }
};

..........................................................................................

// TC : O(n ^ 2)
// SC: O(n)
class Solution {
public:
    vector<int> cache;
    int calculateLIS(int pos, vector<int> &nums)
    {
        if(pos >= nums.size())return 0;
        if(cache[pos] != -1)return cache[pos];
        int lis = 1;
        for(int i = pos + 1; i < nums.size(); i++)
        {
            if(nums[pos] < nums[i])
            {
                lis = max(lis, 1 + calculateLIS(i, nums));
            }
        }
        return cache[pos] = lis;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int lis = 1;
        cache.clear();
        cache.resize(nums.size(), -1);
        for(int i = 0; i < nums.size(); i++)
        {
            lis = max(lis, calculateLIS(i, nums));
        }
        return lis;
    }
};