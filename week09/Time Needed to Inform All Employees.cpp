// TC : O(n) where n = number of employee
// SC : O(n) where n = number of employee
class Solution {
public:
    vector<vector<int>> adjacentNodes;
    int findMinTime(int u, vector<int>& informTime)
    {
        int maxSubordinateTime = 0;
        for(auto v : adjacentNodes[u])
        {
            maxSubordinateTime = max(maxSubordinateTime, findMinTime(v, informTime));
        }
        return maxSubordinateTime + informTime[u];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        adjacentNodes.clear();
        adjacentNodes.resize(n + 1);
        for(int i = 0; i < manager.size(); i++)
        {
            if(manager[i] != -1)
            {
                adjacentNodes[manager[i]].push_back(i);
            }
        }
        return findMinTime(headID, informTime);
    }
};
