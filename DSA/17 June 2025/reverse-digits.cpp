class Solution {
  public:
    int reverseDigits(int n) {
        // Code here
        int result = 0;
        
        while (n > 0){
            result = result*10 + n%10;
            n/=10;
        }
        return result;
    }
};