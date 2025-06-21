// https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = 0;

        for (int i=0; i < n; ++i){
            for (int k = n-1, j=0; j < k; ){
                swap(matrix[k][i], matrix[j][i]);
                ++j;
                --k;
            }
        }
        for (int i=0; i < (n+1)/2; ++i){
            for (int j = (n+1)/2; j >= 0; --j){
                if (i < j){
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }


    }
};