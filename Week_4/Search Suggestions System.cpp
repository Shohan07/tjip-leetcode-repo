//TC : 
//O(n* l) generateTrie() where n is the number of products, l is the average length of product
//O(len(search words length)) suggestedProducts()
// O(3 * (max(product_len)))

//SC : O(s) where s = sum of products length

class Solution {
public:
    class TrieNode
    {
      public :
        string word;
        TrieNode* next[26];
        TrieNode()
        {
            word = "";
            for(int i = 0; i < 26; i++)
            {
                next[i] = NULL;
            }
        }
    };
    TrieNode* generateTrie(vector<string> &products)
    {
        TrieNode* root = new TrieNode();
        for(auto &wd : products)
        {
            TrieNode* cur = root;
            for(auto &c : wd){
                int id = c - 'a';
                if(cur -> next[id] == NULL)cur -> next[id] = new TrieNode();
                cur = cur -> next[id];
            }
            cur -> word = wd;
        }
        return root;
    }
    void dfs(TrieNode* u, vector<string>&words)
    {
        if(u == NULL || words.size() == 3)return;
        if(u -> word.size() > 0 && words.size() < 3){
            words.push_back(u -> word);
        }
        for(int i = 0; i < 26; i++)
        {
            dfs(u -> next[i], words);
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode* root = generateTrie(products);
        vector<vector<string>> suggestions;
        for(auto c : searchWord)
        {
            root = root && root->next[c - 'a'] ? root->next[c - 'a'] : NULL;
            vector<string> words ;
            dfs(root, words);
            suggestions.push_back(words);
        }
        return suggestions;
    }
};