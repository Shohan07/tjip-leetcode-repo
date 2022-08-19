// TC : O(k * L) k= string length, L = Pattern length
// SC L (K * L)
class Solution {
public:
    string s, p;
    vector<vector<short int>> cache;
    short int matches(int sp, int pp){
        if(pp >= p.size()) return cache[sp][pp] = sp == s.size();
        if(cache[sp][pp] != -1)return cache[sp][pp];
        cache[sp][pp] = 0;
        if(p[pp + 1] == '*')
        {
            bool c1 = matches(sp, pp + 2);
            bool c2 = (sp < s.size() && (s[sp] == p[pp] || p[pp] == '.') && (matches(sp + 1, pp)));
            
            cache[sp][pp] = c1 || c2;
        }
        else if(sp < s.size() && (s[sp] == p[pp] || p[pp] == '.'))
        {
            cache[sp][pp] = matches(sp + 1, pp + 1);
        }
        return cache[sp][pp];
    }
   
    bool isMatch(string S, string P) {
        s = S;
        p = P;
        cache.clear();
        cache.resize(s.size() + 1, vector<short int>(p.size() + 1, -1));
        return matches(0, 0);
    }
};