class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> answer(2, -1);
        if(nums.empty())
        {
            return answer;
        }
        bool found = false;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == target)
            {
                if(!found)
                {
                    found = true;
                    answer[0] = i;
                }
            }
            else if(nums[i] > target)
            {
                if(!found)
                {
                    return answer;
                }
                else
                {
                    answer[1] = i - 1;
                    break;
                }
            }
        }
        if(found && answer[1] == -1)
        {
            answer[1] = nums.size() - 1;
        }
        return answer;
    }
};
