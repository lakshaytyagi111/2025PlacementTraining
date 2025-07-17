class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int currentSum = 0;
        vector<vector<int>> result;
        vector<int> path;
        int i = 0;
        backtrack(candidates, result, path, target, currentSum, i);
        return result;
    }
    void backtrack(vector<int>& candidates, vector<vector<int>>& result, vector<int>& path, int target, int currentSum, int start){
        if (currentSum == target){
            result.push_back(path);
            return;
        } 
       
        for (int i = start; i < candidates.size(); i++){
            if (i > start && candidates[i] == candidates[i - 1]){
                continue;
            }
            if (currentSum+candidates[i] > target){
                break;
            }
            path.push_back(candidates[i]);
            backtrack(candidates, result, path, target, currentSum + candidates[i], i+1);
            path.pop_back();
            
        }

    }
};