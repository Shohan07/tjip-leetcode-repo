// TC : O(n)
// SC : O(1)
class Solution {
public:
    int calculate(string s) {
        int currNum = 0, lastNum = 0, ans = 0;
        char sign = '+';
        for(int i = 0; i < s.length(); i++){
            if(isdigit(s[i])){
                currNum = (currNum * 10) + (s[i] - '0');
            }
            if((!isdigit(s[i]) && !isspace(s[i])) || i == s.length() - 1){
                if(sign == '+' || sign == '-'){
                    ans += lastNum;
                    lastNum = (sign == '+') ? currNum : -currNum;
                }
                else if(sign == '*'){
                    lastNum = lastNum * currNum;
                }
                else if(sign == '/'){
                    lastNum = lastNum / currNum;
                }
                sign = s[i];
                currNum = 0;
            }
        }
        ans += lastNum;
        return ans;
    }
};