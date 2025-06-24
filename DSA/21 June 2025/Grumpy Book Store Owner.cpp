// https://leetcode.com/problems/grumpy-bookstore-owner/

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int satisfied = 0;
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                satisfied += customers[i];
            }
        }

        int maxGain = 0, gain = 0;
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 1) {
                gain += customers[i];
            }
            if (i >= minutes) {
                if (grumpy[i - minutes] == 1) {
                    gain -= customers[i - minutes];
                }
            }
            maxGain = max(maxGain, gain);
        }

        return satisfied + maxGain;
    }
};