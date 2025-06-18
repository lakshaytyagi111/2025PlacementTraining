// https://leetcode.com/problems/search-insert-position/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while (left <= right){
            int idx = left + (right - left)/2;
            if (nums[idx] > target){
                right = idx-1;
            } else if (nums[idx] < target){
                left = idx+1;
            } else {
                return idx;
            }
        }
        return left;
    }
};