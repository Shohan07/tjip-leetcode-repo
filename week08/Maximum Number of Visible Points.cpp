// TC : O(N)
// SC : O(N)
class Solution {
public:
    double getAngle(double dy, double dx){
        double rad = atan2(dy, dx);
        double deg = rad * 180.0 / acos(-1);
        return deg < 0 ? deg + 360 : deg;
    }
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double>angles;
        int duplicate = 0;
        for(auto point : points){
            if(point == location)duplicate++;
            else
                angles.push_back(getAngle(point[1] - location[1], point[0] - location[0]));
        }
        sort(angles.begin(), angles.end());
        
        int mxPoint = 0;
        int n = angles.size();
        for(int lr = 0, ur = 0; lr < n; lr++){
            while((ur < n && angles[ur] - angles[lr] <= angle) ||
                  (ur >= n && 360 + angles[ur % n] - angles[lr] <= angle)){
                ur++;
            }
            mxPoint = max(mxPoint, ur - lr);
        }
        return mxPoint + duplicate;
    }
};