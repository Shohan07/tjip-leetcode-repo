//TC : O(n)
//SC : O(n)
class DetectSquares {
public:
    map<pair<int, int>, int> points;
    DetectSquares() {
        points.clear();
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        points[{x, y}]++;
    }
    
    int count(vector<int> qpoint) {
        int totalCnt = 0;
        int x1 = qpoint[0];
        int y1 = qpoint[1];
        for(auto point : points){
            int x3 = point.first.first;
            int y3 = point.first.second;
            
            if((x1 == x3) || (abs(x1 - x3) != abs(y1 - y3)))continue;
            
            if(points.count({x3, y1}) && points.count({x1, y3})){
                totalCnt += points[{x3, y1}] * points[{x1, y3}] * points[{x3, y3}];
            }
        }
        return totalCnt;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */

.........................................................................


// TC : add() : O(1)
// TC : count() : O(n)
// SC : O(n)
class DetectSquares {
public:
    unordered_map<long long, int> points;
    int base = 1e9 + 7;
    long long getSerializedValue(pair<int, int>p){
        return (1LL * p.first * base) + p.second;
    }
    DetectSquares() {
        points.clear();
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        points[getSerializedValue({x, y})]++;
    }
    
    int count(vector<int> qpoint) {
        int totalCnt = 0;
        int x1 = qpoint[0];
        int y1 = qpoint[1];
        for(auto point : points){
            int x3 = point.first / base;
            int y3 = point.first % base;
            
            if((x1 == x3) || (abs(x1 - x3) != abs(y1 - y3)))continue;
            
            if(points.count(getSerializedValue({x3, y1})) && points.count(getSerializedValue({x1, y3}))){
                totalCnt += points[getSerializedValue({x3, y1})] * points[getSerializedValue({x1, y3})] * points[getSerializedValue({x3, y3})];
            }
        }
        return totalCnt;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */