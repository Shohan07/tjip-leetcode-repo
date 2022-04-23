//TC : O(S) where S is the sum of all characters in all strings
//SC : O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        if(strs.empty()) return prefix;
        
        for(int i = 0; i < strs[0].size(); i++){
            for(int j = 1; j < strs.size(); j++){
                if(strs[j][i] != strs[0][i])return prefix;
            }
            prefix += strs[0][i];
        }
        return prefix;
    }
};

......................................................................
//TC : O(log(n))
//SC : O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        int n = v.size();
        if(n == 0) return "";
        
        string ans = "";
        
        sort(v.begin(), v.end());
        string a = v[0];
        string b = v[n-1];
        
        for(int i = 0; i < a.size(); i++){
            if(a[i] == b[i]){
                ans = ans + a[i];
            }
            else{
                break;
            }
        }
        return ans;
    }
};