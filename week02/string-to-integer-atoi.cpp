//TC : O(n);
//SC : O(1);
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, ans = 0;
        int sign = 1;
        
        while(s[i] == ' ') i++;
        
        if(s[i] == '-' || s[i] == '+'){
            sign = s[i] == '-' ? -1 : 1;
            i++;
        }
        while(s[i] >= '0' && s[i] <= '9'){
            if(ans > INT_MAX/10 || (ans == INT_MAX/10 && s[i] > '7')){
                return sign == -1 ? INT_MIN : INT_MAX;
            }
            ans = 10 * ans + (s[i] - '0');
            i++;
        }
        return sign * ans;
    }
};