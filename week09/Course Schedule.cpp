//TC : O( numCourses + prerequesties.size() )
//SC : O( numCourses )
class Solution {
public:
    bool hasCycle(int u, vector<vector<int>> &gr, vector<int> &color){
        color[u] = 1;
        bool status = false;
        for(auto v : gr[u]){
            if(color[v] == 1) status = true;
            else if(color[v] == 0){
                status |= hasCycle(v, gr, color);
            }
        }
        color[u] = 2;
        return status;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> gr(numCourses);
        vector<int>color(numCourses, 0);
        
        for(int i = 0; i < prerequisites.size(); i++){
            gr[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        for(int i = 0; i < numCourses; i++){
            if(color[i] == 0){
                if(hasCycle(i, gr, color))return false;
            }
        }
        return true;
    }
};
