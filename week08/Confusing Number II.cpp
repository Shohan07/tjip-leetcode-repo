// TC : O(log(N))
// SC : O(1)
class Solution {
public:
    int cnt = 0;
    void backtrack(long long validNumber, long long rotationNumber, long long digit, int N, vector<int>& valid, unordered_map<int, int>& digits){
        if(validNumber != rotationNumber){
            cnt++;
        }
        for(auto i : valid){
            if(validNumber * 10 + i > N){
                break;
            }
            else{
                backtrack(validNumber * 10 + i, digits[i] * digit + rotationNumber, digit * 10, N, valid, digits);
            }
        }
    }
    
    int confusingNumberII(int N) {
        vector<int> valid = {0,1,6,8,9};
        unordered_map<int, int> digits = {{0, 0},{1,1},{6,9},{8,8},{9,6}};
        backtrack(1, 1, 10, N, valid, digits);
        backtrack(6, 9, 10, N, valid, digits);
        backtrack(8, 8, 10, N, valid, digits);
        backtrack(9, 6, 10, N, valid, digits);
        return cnt;
    }
};