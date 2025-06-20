// https://leetcode.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int n = digits.size();
        vector<int> result(digits.size()+1);

        while(n>0){
            if (digits[n-1] +1 == 10 && carry){
                result[n] = 0;
                carry = 1;
                n--;
            } else if (carry && n!=0){
                result[n] = digits[n-1]+1;
                carry = 0;
                n--;
            } else {
                result[n] = digits[n-1];
                n--;
            }
        }
        if (carry){
            result[0] = 1;
            return result;
        } else {
            vector<int> trimmed;
            for (int i=1; i < result.size() ; i++){
                trimmed.push_back(result[i]);
            }
            return trimmed;
        }
    }
};