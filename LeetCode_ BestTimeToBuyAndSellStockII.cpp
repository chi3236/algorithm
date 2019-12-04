class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 1)
        {
            return 0;
        }
        int answer = 0;
        for(int i = 0; i < prices.size()-1; i++)
        {
            if(prices[i + 1] > prices[i])
            {
                answer += prices[i + 1] - prices[i];
            }
        }
        return answer;
    }
};
