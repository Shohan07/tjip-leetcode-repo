// TC : O(log n)
// SC : O(1)
class Solution {
public:
    double modularExpo(double x, long long n){
        double currProd = x, ans = 1;
        for(long long i = n; i > 0; i /= 2){
            if((i % 2) == 1){
                ans = ans * currProd;
            }
            currProd = currProd * currProd;
        }
        return ans;
    }
    double myPow(double x, int n) {
        bool neg = n < 0;
        if(n == 0)return 1.0;
        long long bn = n < 0 ? 1LL * (-1) * n : n;
        double ans = modularExpo(x, bn);
        ans = neg ? 1.0 / ans : ans;
        return ans;
    }
};