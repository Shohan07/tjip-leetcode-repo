// TC : O(N * log(k))where N = number of trains, K = range of speed
// SC : O(1)
class Solution {
private:
    bool canReachInTime(vector<int>& dist, double hour, int speed){
        double time = 0;
        for(int i = 0; i < dist.size() - 1; ++i){
            time += ((dist[i] + speed - 1) / speed);
        }
        time += (dist.back() * 1.0) / speed;
        
        return time <= hour;
    }
    
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int N = dist.size();
        
        if(hour <= (double)(N - 1)) return -1;
        
        int low = 1, high = 1e7, mid;
        while(low < high){
            mid = low + (high - low) / 2;
            if(canReachInTime(dist, hour, mid)){
                high = mid;
            }
            else low = mid + 1;
        }
        return high;
    }
};