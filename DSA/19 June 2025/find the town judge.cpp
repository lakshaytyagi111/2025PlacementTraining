// https://leetcode.com/problems/find-the-town-judge/description/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> test;

        for (int i=1; i <= n; ++i){
            test[i] = 0;
        }

        for (int i = 0; i < trust.size(); ++i){
            test[trust[i][0]] -= 1;
            test[trust[i][1]] += 1;
        }

        for (int i = 1; i <= n; ++i){
            if (test[i] == n-1){
                return i;
            }
        }

        return -1;
    }
};