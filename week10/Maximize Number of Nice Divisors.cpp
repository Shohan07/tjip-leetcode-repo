// TC : O(log (n))
// SC : O(1)
class Solution {
public:
    static const int MOD = 1e9 + 7;
    long long modPower(int n, int m)
    {
        if(m == 0) return 1;
        if(m % 2 == 0)
        {
            long long t = modPower(n, m / 2);
            return (t * t) % MOD;
        }
        return (n * modPower(n, m - 1)) % MOD;
    }
    
    int maxNiceDivisors(int pF) {
        if(pF == 1) return 1;
        else if(pF % 3 == 0) return modPower(3, pF / 3);
        else if(pF % 3 == 1) return (4 * modPower(3, (pF - 2) / 3)) % MOD;
        return (2 * modPower(3, pF / 3)) % MOD;
    }
};