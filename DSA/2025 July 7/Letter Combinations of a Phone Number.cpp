// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()){
            return {};
        }
        vector<string> result;
        string path;
        vector<string> table = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
        };
        backtrack(digits, result, 0, path, table);
        return result;
    }
    void backtrack(string& digits, vector<string>& result, int index, string& path, vector<string>& table){
        if (path.length() == digits.size()){
            result.push_back(path);
            return;
        }
        int digit = digits[index] - '0';
        const string& letters = table[digit];

        for(char c: letters){
            path.push_back(c);
            backtrack(digits, result, index+1, path, table);
            path.pop_back();
        }
    }
};