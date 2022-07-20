// TC : O(M * N) as grid size M * N
// SC : O(M * N) at most M * N points into the queue

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms)
    {
        int n = rooms.size();
        if(n == 0) return;
        int m = rooms[0].size();
        
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(rooms[i][j] == 0)
                {
                    q.push({i, j});
                }
            }
        }
        while(!q.empty())
        {
            auto u = q.front();
            q.pop();
            int d[] = {0, 1, 0, -1, 0};
            for(int i = 0; i < 4; i++)
            {
                int X = u.first + d[i];
                int Y = u.second + d[i + 1];
                if(X >= 0 && Y >= 0 && X < n && Y < m)
                {
                    if(rooms[u.first][u.second] + 1 < rooms[X][Y])
                    {
                        rooms[X][Y] = rooms[u.first][u.second] + 1;
                        q.push({X, Y});
                    }
                }
            }
        }
    }
};
