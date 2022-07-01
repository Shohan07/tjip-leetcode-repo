// TC : O(log n)
// SC : O(1)
class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;
        double prev = x;
        double x1 = (prev + x / prev) / 2.0;
        
        while(fabs(prev - x1) >= 1){
            prev = x1;
            x1 = (prev + x / prev) / 2.0;
        }
        
        return (int)x1;
    }
};