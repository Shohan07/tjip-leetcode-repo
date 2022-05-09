//TC : O(NlogN + N*L^2)
//SC : O(N)
class Solution {
public:
    static bool comp(string a, string b){
        return a.size() < b.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        unordered_map<string, int> mp;
        int ans = 0;
        for(auto &word : words){
            int mx_len = 0;
            for(int i = 0; i < word.size(); i++){
                string pwd = word.substr(0, i) + word.substr(i + 1);
                mx_len = max(mx_len, mp[pwd] + 1);
            }
            mp[word] = mx_len;
            ans = max(ans, mx_len);
        }
        return ans;
    }
};
