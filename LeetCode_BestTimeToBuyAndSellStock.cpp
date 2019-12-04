class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty() || prices.size() == 1)
        {
            return 0;
        }
        int answer = 0;
        int buy = prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            if(buy > prices[i])
            {
                buy = prices[i];
            }
            else
            {
                answer = max(answer, prices[i] - buy);
            }
        }
        return answer;
    }
};
