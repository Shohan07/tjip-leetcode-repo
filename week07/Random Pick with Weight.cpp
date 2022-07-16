/*TC : 
For Constructor: O(N) N is the size of vector
For pickIndex : O(log(N))
SC : 
For Constructor: O(N) N is the size of vector
For pickIndex : O(1)
*/
mt19937 rd(0);
class Solution {
public:
    vector<int> sw;
   
    int getRandomInRange(int L, int R){
        return L + (rd() % (R - L + 1));
    }
    Solution(vector<int>& w) {
        sw = w;
        for(int i = 1; i < sw.size(); i++){
            sw[i] = sw[i - 1] + w[i];
        }
    }
    
    int pickIndex() {
        int totalSum = sw.back();
        int randVal = getRandomInRange(1, totalSum);
        return lower_bound(sw.begin(), sw.end(), randVal) - sw.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */