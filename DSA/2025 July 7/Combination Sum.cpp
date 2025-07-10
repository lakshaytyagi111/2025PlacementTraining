// https://leetcode.com/problems/combination-sum/description/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> path;
        int currentSum = 0;
        int start = 0;
        backtrack(candidates, target, path, currentSum, start, result);
        return result;
    }

    void backtrack(vector<int>& candidates, int target, vector<int>& path, int currentSum, int start, vector<vector<int>>& result){
        if (currentSum == target){
            result.push_back(path);
            return;
        }

        for (int i=start; i < candidates.size(); ++i){
            if (currentSum + candidates[i] > target){
                break;
            }

            path.push_back(candidates[i]);
            backtrack(candidates, target, path, currentSum + candidates[i], i, result);
            path.pop_back();
        }

    }
};