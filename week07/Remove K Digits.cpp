// TC : O(N)
// SC : O(N)
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>stk;
        stk.push(num[0]);
        for(int i = 1; i < num.length(); i++){
            while(k > 0 && !stk.empty() && stk.top() > num[i]){
                stk.pop();
                k--;
            }
            stk.push(num[i]);
        }
        while(k > 0 && !stk.empty()){
            stk.pop();
            k--;
        }
        string ans;
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        while(!ans.empty() && ans.back() == '0'){
            ans.pop_back();
        }
        if(ans.empty())return "0";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};