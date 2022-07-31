// TC : O(C(n))
//SC : O(C(n) + 2n) where nth Catalan Num C(n) = (2n C n) * (1 / (n + 1))
class Solution {
public:
    vector<string> results;
    void generate(string &curr, int open, int close)
    {
        if(open == close && open == 0)
        {
            results.push_back(curr);
            return;
        }
        if(open > 0)
        {
            curr.push_back('(');
            generate(curr, open - 1, close);
            curr.pop_back();
        }
        if(open < close)
        {
            curr.push_back(')');
            generate(curr, open, close - 1);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        results.clear();
        string curr = "";
        generate(curr, n, n);
        
        return results;
    }
};