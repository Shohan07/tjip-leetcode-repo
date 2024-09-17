// TC : O(n ^ 2)
// SC : O(n ^ 2)
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size(), start = 0, end = 1;
        vector<vector<bool>> dp(len, vector<bool> (len, false));
        
        for(int i=0;i<len;i++)
        {
            dp[i][i] = true;
        }
        
    string ans = "";
        ans += s[0];

        for (int i = len - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < len; j++)
            {
                if (s[i] == s[j])
                {
                    if (j - i == 1 || dp[i + 1][j - 1])
                    {
                        dp[i][j] = true;
                        if (ans.size() < j - i + 1)
                            ans = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return ans;
    }
};