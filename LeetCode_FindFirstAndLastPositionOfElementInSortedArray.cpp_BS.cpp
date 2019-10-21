class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> answer(2, -1);
        if(nums.empty())
        {
            return answer;
        }
        bool found = false;
        int hi = nums.size();
        int lo = 0;
        while(lo < hi)
        {
            int mid = (lo + hi) / 2;
            if(nums[mid] >= target)
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
        if(lo >= nums.size() || lo < 0)
        {
            return answer;
        }
        if(nums[lo] == target)
        {
            found = true;
            answer[0] = lo;
        }
        if(found)
        {
            hi = nums.size();
            lo = 0;
            while(lo < hi)
            {
                int mid = (lo + hi) / 2;
                if(nums[mid] > target)
                {
                    hi = mid;
                }
                else
                {
                    lo = mid + 1;
                }
            }
            answer[1] = lo-1;
        }
        return answer;
    }
};
