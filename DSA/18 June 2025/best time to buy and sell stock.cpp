// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int smallest = prices[0];
        int n = prices.size();
        int maxProfit = 0;

        for (int i=0; i < n; ++i){
            if (prices[i] < smallest){
                smallest = prices[i];
            } else {
                maxProfit = max(maxProfit, prices[i]-smallest);
            }
        }
        return maxProfit;        
    }
};