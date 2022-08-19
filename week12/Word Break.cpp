//TC : O(max(S, N^2)). Here N is the length of the string, and S is the sum of length of all words in the dictionary.
//SC : O(S) where  S = sum of words length
class Solution {
public:
    class TrieNode
    {
      public :
        bool isWord;
        TrieNode* next[26];
        TrieNode()
        {
            isWord = false;
            for(int i = 0; i < 26; i++)
            {
                next[i] = NULL;
            }
       }
    };
    TrieNode* buildTrie(vector<string> &wordDict)
    {
        TrieNode* root = new TrieNode();
        for(auto &wd : wordDict)
        {
            TrieNode* currNode = root;
        for(auto &c : wd)
        {
            int order = c - 'a';
            if(currNode -> next[order] == NULL)
            {
                 currNode -> next[order] = new TrieNode();
            }
            currNode = currNode -> next[order];
        }
        currNode -> isWord = true;
        }
        return root;
    }
    void search(string s, TrieNode* root, int start,  vector<bool> &dp){
        TrieNode* currNode = root;
        int len = s.length();
         for (int j = start; j < len; j++){
            int order = s[j] - 'a';
            if (currNode -> next[order] == NULL){
                break;
            }
            currNode = currNode -> next[order];
            if (currNode && (currNode -> isWord)){
                dp[j+1] = true;
            }
         }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root = buildTrie(wordDict);
        
        int len = s.length();
        vector<bool> dp(len + 1, false);
        dp[0] = true;
        for(int i = 0; i <= len; i++){
            if(dp[i]){
                search(s, root, i, dp);
            }
        }
        return dp[len];
    }
};