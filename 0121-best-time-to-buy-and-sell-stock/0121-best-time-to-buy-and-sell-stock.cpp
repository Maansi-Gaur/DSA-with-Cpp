class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy= prices[0];
        int profit= INT_MIN;
        int maxp= INT_MIN;
        for(int i=0; i<prices.size(); i++){
            profit= prices[i]-buy;
            maxp= max(maxp,profit);
            buy= min(buy,prices[i]);
        }
        return maxp;
    }
};