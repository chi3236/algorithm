class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }
        int answer = 0;
        int currMax = 0;
        int next = 0;
        for(int i = 0; i < nums.size()-1; i++)
        {
            next = max(next, nums[i] + i);
            if(i == currMax)
            {
                answer++;
                currMax = next;
            }
        }
        return answer;
    }
};