// TC : (n) n = number of digits after decimal point
// SC : (n) n = number of digits after decimal point
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return 0;
        string ans;
        if(numerator < 0 ^ denominator < 0) ans += "-";
        long long n = abs(numerator), d = abs(denominator);
        
        ans += to_string(n / d);
        if(n % d == 0)return ans;
        ans += ".";
        long long r = n % d;
        
        unordered_map<long long, int> mp;
        while(r){
            if(mp.count(r)){
                ans.insert(mp[r], "(");
                ans += ")";
                break;
            }
            mp[r] = ans.size();
            r *= 10;
            ans += to_string(r / d);
            r %= d;
        }
        return ans;
    }
};