class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        if(nums.size() == 0)
        {
            return answer;
        }
        sort(nums.begin(), nums.end());
        int l, h, curr, target;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            l = i + 1;
            h = nums.size() - 1;
            target = -nums[i];
            while(l < h)
            {
                curr = nums[l] + nums[h];
                if(curr == target)
                {
                    vector<int> answerNum{nums[i], nums[l], nums[h]};
                    answer.push_back(answerNum);
                    while(l < h && nums[l] == nums[l + 1])
                    {
                        l++;
                    }
                    while(l < h && nums[h] == nums[h - 1])
                    {
                        h--;
                    }
                    l++;
                    h--;
                }
                else if(curr > target)
                {
                    while(l < h && nums[h] == nums[h - 1])
                    {
                        h--;
                    }
                    h--;
                }
                else
                {
                    while(l < h && nums[l] == nums[l + 1])
                    {
                        l++;
                    }
                    l++;
                }
            }
        }
        return answer;
    }
};
