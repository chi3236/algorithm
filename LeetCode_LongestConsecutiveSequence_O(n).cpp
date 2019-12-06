class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }
        int answer = 1;
        unordered_set<int> s(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            if(s.find(nums[i]) == s.end())
            {
                continue;
            }
            int prev = nums[i] - 1;
            int next = nums[i] + 1;
            s.erase(nums[i]);
            while(s.find(prev) != s.end())
            {
                s.erase(prev--);
            }
            while(s.find(next) != s.end())
            {
                s.erase(next++);
            }
            answer = max(answer, next - prev - 1);
        }
        return answer;
    }
};