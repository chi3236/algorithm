class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }
        priority_queue<int> pq;
        for(int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
        }
        int prev = pq.top();
        pq.pop();
        int answer = -1;
        int count = 1;
        while(!pq.empty())
        {
            int curr = pq.top();
            pq.pop();
            if(prev == (curr + 1))
            {
                count++;
            }
            else if (prev == curr)
            {
                continue;
            }
            else
            {
                answer = max(answer, count);
                count = 1;
            }
            prev = curr;
        }
        answer = max(answer, count);
        return answer;
    }
};