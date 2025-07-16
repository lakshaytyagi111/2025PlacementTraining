// 213. House Robber 2
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        
        return max(robbing(nums, 0, nums.size()-2), robbing(nums, 1, nums.size() - 1));
    }

    int robbing(vector<int>& nums, int start, int end){
        int prev1 = 0, prev2 = 0;
        for (int i = start; i <= end; i++){
            int curr = max(prev1, prev2+nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};