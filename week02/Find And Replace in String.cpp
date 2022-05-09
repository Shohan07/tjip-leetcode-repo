//TC : O(N)
//SC : O(N)
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices,
                vector<string>& sources, vector<string>& targets) {
        vector<int>mp(s.length(), 0);
        string ans = "";
        
        for(int i = 0; i < indices.size(); i++){
            bool f = true;
            for(int j = 0; j < sources[i].size(); j++){
                if(indices[i] + j == s.length() || s[indices[i] + j] != sources[i][j]){
                    f = false;
                    break;
                }
            }
            if(f) {
                mp[indices[i]] = i + 1;
            }
        }
        
        for(int i = 0; i < s.length(); i++){
            if(mp[i]){
                ans += targets[mp[i] - 1];
                i += sources[mp[i] - 1].length() - 1;
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};