// https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int temp = 0;

        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] == 1){
                temp+=1;
                maxi = max(maxi, temp);
            } else {
                temp = 0;
            }
        }
        return maxi;
    }
};