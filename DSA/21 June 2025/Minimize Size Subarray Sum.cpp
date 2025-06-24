// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int minlength = INT_MAX;

        for (int right = 0; right < nums.size(); right++){
            sum += nums[right];

            while (sum >= target){
                minlength = min(minlength, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return (minlength == INT_MAX) ? 0 : minlength;
    }
};