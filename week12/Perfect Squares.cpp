// TC : O (sqrt(n))
// SC : O(1)
class Solution {
public:
    bool is_square(int n)
    {
        int tmp = (int)(sqrt(n));
        return (tmp * tmp == n);
    }
    
    int numSquares(int n) 
    {
        while(n % 4 == 0) n /= 4;
        if(n % 8 == 7) return 4;
        
        if(is_square(n))return 1;
        
        for(int i = 1; i * i <= n; i++)
        {
            if(is_square(n - (i * i)))return 2;
        }
        return 3;
    }
};

..........................................................................................

// TC : O (n * sqrt(n))
// SC : O(n)
class Solution {
public:
    int numSquares(int n) {
        vector<int> cache(n + 1, INT_MAX / 2);
        cache[0] = 0;
        cache[1] = 1;
        
        for(int curr = 1; curr <= n; curr++)
        {
            for(int sq = 1; sq * sq <= curr; sq++)
            {
                cache[curr] = min(cache[curr], 1 + cache[curr - (sq * sq)]);
            }
        }
        return cache[n];
    }
};
