class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int lowest = prices[0];
        int maxProfit = 0;
        for(int i=1; i<n; i++){
            if(prices[i] < lowest) lowest = prices[i];
            else{
                int currProfit = prices[i] - lowest;
                if(maxProfit < currProfit) maxProfit = currProfit;
            } 
        }
        return maxProfit;
    }
};
