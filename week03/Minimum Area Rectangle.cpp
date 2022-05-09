//TC : O(n^2)
//SC : O(n)
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> mp;
        
        for(auto& point : points){
            mp[point[0]].insert(point[1]);
        }
        
        int minArea = INT_MAX;
        for(int i = 0; i < points.size() - 1; i++){
            for(int j = i + 1; j < points.size(); j++){
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                
                if(x1 == x2 || y1 == y2)continue;
                if(mp[x1].count(y2) && mp[x2].count(y1)){
                    minArea = min(minArea, abs(x1 - x2) * abs(y1 - y2));
                }
            }
        }
        return minArea == INT_MAX ? 0 : minArea;
    }
};