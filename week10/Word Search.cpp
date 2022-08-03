// TC : O(M * N * 3 ^ L) where M*N = grid, L = word length
// SC : O(L)
class Solution {
public:
    int n, m;
    const int dir[5] = {1, 0, -1, 0, 1};
    bool dfs(int r, int c, int wPos, vector<vector<char>> &board, string &word, vector<vector<bool>> &vis)
    {
        if(wPos >= word.size()) return true;
        if(r < 0 || c < 0 || r >= n || c >= m || vis[r][c])return false;
        vis[r][c] = 1;
        bool status = false;
        for(int i = 0; i < 4; i++)
        {
            int R = r + dir[i];
            int C = c + dir[i + 1];
            if(word[wPos] == board[r][c])
            {
                status |= dfs(R, C, wPos + 1, board, word, vis);
            }
            if(status)break;
        }
        vis[r][c] = 0;
        return status;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(word[0] == board[i][j])
                {
                    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, 0));
                    bool status = dfs(i, j, 0, board, word, vis);
                    if(status) return true;
                }
            }
        }
        return false;
    }
};