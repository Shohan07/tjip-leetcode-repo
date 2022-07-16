// TC : O(Nlog(N)) where N = intervals size
// SC : O(N)
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> stats;
        for(auto interval : intervals){
            stats[interval[0]]++;
            stats[interval[1]]--;
        }
        int curr = 0, minRoom = 0;
        for(auto stat : stats){
            curr += stat.second;
            minRoom = max(minRoom, curr);
        }
        return minRoom;
    }
};