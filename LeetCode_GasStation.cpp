class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.empty() || cost.empty())
        {
            return -1;
        }
        int n = gas.size();
        int currSum = 0;
        int sum = 0;
        int answer = 0;
        for(int i = 0; i < n; i++)
        {
            currSum += gas[i] - cost[i];
            if(currSum < 0)
            {
                sum += currSum;
                currSum = 0;
                answer = i+1;
            }
        }
        sum += currSum;
        return sum < 0 ? -1:answer;
    }
};
