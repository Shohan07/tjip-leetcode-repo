//TC : O(N) where N = nums.size()
//SC : O(1)
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxRechable = 0, currJumpEnd = 0,  jumps = 0; 
        for(int i = 0; i < nums.size() - 1; i++){
            maxRechable = max(maxRechable, nums[i] + i);
            if(i == currJumpEnd){
                jumps++;
                currJumpEnd = maxRechable;
            }
        }
        return jumps;
    }
};