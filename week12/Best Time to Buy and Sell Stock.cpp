// TC : O(n) n = number of prices 
// SC : O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices){
        int minPrice = INT_MAX, maxProf = 0; 
        for(int i = 0; i < prices.size(); i++){
            minPrice = min(minPrice, prices[i]);
            maxProf = max(maxProf, prices[i] - minPrice);
        }
        return maxProf;
    }
};