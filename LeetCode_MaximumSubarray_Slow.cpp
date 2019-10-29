class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }
        int n = nums.size();
        vector<int> sums(n+1, 0);
        int answer = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            sums[i+1] = sums[i] + nums[i];
            answer = max(answer, nums[i]);
        }
        for(int i = 2; i < n+1; i++)
        {
            for(int j = i; j < n+1; j++)
            {
                answer = max(answer, sums[j] - sums[j-i]);
            }
        }
        return answer;
    }
};
