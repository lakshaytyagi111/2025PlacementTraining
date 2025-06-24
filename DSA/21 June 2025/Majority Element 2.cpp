// https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int range = n/3;
        unordered_map<int, int> seen;
        for (auto x: nums){
            if (seen.find(x) != seen.end()){
                seen[x] += 1;
            } else {
                seen[x] = 1;
            }
        }
        vector<int> result;
        for (auto y: seen){
            if (y.second > range){
                result.push_back(y.first);
            }
        }
        return result;
    }
};

// ----------------------------------------------------
// In this particular solution only two numbers are possible which appear more than n/3 times in an array
// space cmoplexity O(1)
// time complexity O(n)
// Boyer-Moore voting problem

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0, candidate2 = 1; 
        int count1 = 0, count2 = 0;

        // 1st pass: find potential candidates
        for (int num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
            else if (count1 == 0) { candidate1 = num; count1 = 1; }
            else if (count2 == 0) { candidate2 = num; count2 = 1; }
            else { count1--; count2--; }
        }

        // 2nd pass: verify the candidates
        count1 = count2 = 0;
        for (int num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }

        vector<int> result;
        int threshold = nums.size() / 3;
        if (count1 > threshold) result.push_back(candidate1);
        if (count2 > threshold) result.push_back(candidate2);

        return result;
    }
};