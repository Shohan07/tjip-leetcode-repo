// TC : O(logn)
// SC : O(1)
class Solution {
public:
    int firstBadVersion(int n) {
        int L = 1, R = n;
        while(L < R){
            int M = L + (R-L)/2;
            if(isBadVersion(M) == 0) L= M+1;
            else R = M;
        }
        return L;
    }
};