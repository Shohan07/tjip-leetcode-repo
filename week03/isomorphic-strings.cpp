//TC : O(N)
//SC : O(1) because vector size is constant

class Solution {
public:
    bool isIsomorphic(string s, string t, int iteration_cnt = 0) {
       vector<int>StoT(256, -1), TtoS(256, -1);
        for(int i = 0; i < s.size(); i++){
            if(StoT[s[i]] != TtoS[t[i]]){
                return false;
            }
            StoT[s[i]] = TtoS[t[i]] = i + 1;
       }
       return true;
    }
};
.................................................................................

//TC : O(N)
//SC : O(N)
class Solution {
public:
    bool isIsomorphic(string s, string t, int iteration_cnt = 0) {
        unordered_map<int, char> mp;
        for(int i = 0; i < s.size(); i++){
            if(mp[s[i]] && mp[s[i]] != t[i]){
                return false;
            } 
            mp[s[i]] = t[i];
        }
        if(iteration_cnt == 0)return isIsomorphic(t, s, 1);
        return true;
    }
};
