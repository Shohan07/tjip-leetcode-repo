//TC : O(nlogn)
//SC : O(n)
class Solution {   
public:
    static bool compare(string a, string b){
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        string s = "";
        vector<string> str;
        for(auto x : nums){
            str.push_back(to_string(x));
        }
        sort(str.begin(), str.end(), compare);
        if(str[0] == "0")return "0";
        for(auto x : str){
            s += x;
        }
        return s;
    }
};