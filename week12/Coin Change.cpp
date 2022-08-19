// TC : O(S * n) where S = amount, n = number of coins 
// SC : O(S)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> minWays(amount + 1, INT_MAX / 2);
        minWays[0] = 0;
        for(int coin : coins){
            for(int am = coin; am <= amount; am++){
                minWays[am] = min(minWays[am], minWays[am - coin] + 1);
            }
        }
        return minWays[amount] == INT_MAX / 2 ? -1 : minWays[amount]; 
    }
};