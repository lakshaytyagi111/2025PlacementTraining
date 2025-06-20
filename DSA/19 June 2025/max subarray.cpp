// https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int maxs = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            maxs = max(maxs + nums[i], nums[i]);

            res = max(res, maxs);

        }
        return res;
    }
};