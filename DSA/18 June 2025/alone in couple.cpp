// https://www.geeksforgeeks.org/problems/alone-in-couple5507/0

class Solution {
  public:
    int findSingle(vector<int> &arr) {
        // code here
        int res =0;
        
        for(int i:arr){
            res = res^i;
        }
        return res;
    }
};