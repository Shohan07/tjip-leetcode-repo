// TC : O(n * m) where n = number of row & m = number of column
// SC : (1)
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) 
    {
        int numBattleships = 0;
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if((board[i][j] == '.') || (i > 0 && board[i - 1][j] == 'X') || 
                   (j > 0 && board[i][j - 1] == 'X'))
                {
                    continue;
                }
                numBattleships++;
            }
                
        }
       
        return numBattleships;
    }
};
