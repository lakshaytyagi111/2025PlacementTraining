// https://leetcode.com/problems/missing-number/description/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for (auto x: nums){
            sum += x;
        }
        int n = nums.size();
        int expected = n*(n+1)/2;

        return expected - sum;
    }
};