// TC : O(4 ^ N * N) , where N is the length of digits
// SC : O(N) 
class Solution {
public:
    vector<string> ans;
    string keyPad[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
   
    void backtrack(int idx, string &path, string &digits){
        if(idx == digits.size()){
            ans.push_back(path);
            return;
        }
        for(char ch : keyPad[digits[idx] - '0']){
            path[idx] = ch;
            backtrack(idx + 1, path, digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return ans;
        string path = digits;
        backtrack(0, path, digits);
        return ans;
    }
};