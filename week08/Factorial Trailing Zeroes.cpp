// TC : O(log n)
// SC : O(1)
class Solution {
public:
    int trailingZeroes(int n) {
        int cnt5 = 0, d = 5;
        while(d <= n){
            cnt5 += n / d;
            d *= 5;
        }
        return cnt5;
    }
};