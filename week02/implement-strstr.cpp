//TC : O(n)
//SC : O(n)
class Solution {
private:
    vector<int> ge_prefix(string s)
    {
        int n = s.size();
        vector<int> lps(n, 0);
        for(int R = 1; R < n; R++){
            int L = lps[R - 1];
            while(L > 0 && s[L] != s[R]){
                L = lps[L - 1];
            }
            lps[R] = L + (s[L] == s[R]);
        }
        return lps;
    }
    
public:
int strStr(string haystack, string needle){
    if(needle.length() == 0)return 0;
    vector<int> lps = ge_prefix(needle);
    int i = 0, j = 0, hl = haystack.length(), nl = needle.length();
    
    while(i < hl){
        if(haystack[i] == needle[j]){
            i++, j++;
        }
        else{
            if(j > 0) j = lps[j - 1];
            else i++;
        }
        if(j == nl)return i - j;
      }
    return -1;
    }
};