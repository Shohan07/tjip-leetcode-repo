//TC :
// O( NM * (4 * 3 ^ word_length) ) Where NM for dfs call and for dfs (4 * 3 ^ word_length)

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
    vector<int> direction{-1, 0, 1, 0, -1};
    
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
    
    void dfs(int x, int y, vector<vector<char>>& board, TrieNode* curNode, vector<string>& wordsOfBoard)
    {
        char ch = board[x][y];
        if(ch == '#' || (curNode && curNode -> next[ch - 'a'] == NULL)) return;
        curNode = curNode -> next[ch - 'a'];
        
        if(curNode && curNode -> word.size() > 0)
        {
            wordsOfBoard.push_back(curNode -> word);
            curNode -> word.clear();
        }
        board[x][y] = '#';
        
        for(int i = 0; i < 4; i++)
        {
            int X = x + direction[i];
            int Y = y + direction[i + 1];
            if(X < 0 || Y < 0 || X >= board.size() || Y >= board[0].size() || board[X][Y] == '#')continue;
            dfs(X, Y, board, curNode, wordsOfBoard);
        }
        board[x][y] = ch;
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = generateTrie(words);
        vector<string> wordsOfBoard;
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++){
                dfs(i, j, board, root, wordsOfBoard);
            }
        }
        return wordsOfBoard;
    }
};