//TC : O(n)
//SC : O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sz = s.size();
        if(sz == 0)return 0;
        int start = 0, end = 0, ans = 0;
        unordered_map<char, int> cnt;
        while(end < sz){
            cnt[s[end]]++;
            while(cnt[s[end]] > 1){
                cnt[s[start]]--;
                start++;
            }
            ans = max(ans, end - start + 1);
            end++;
        } 
        return ans;
    }
};