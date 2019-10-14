class Solution {
public:
    int search(vector<int>& nums, int target) {
        int answer = -1;
        if(nums.empty())
        {
            return answer;
        }
        int lowest;
        if(nums[0] < nums[nums.size() - 1])
        {
            lowest = 0;
        }
        else
        {
            int lo = 0;
            int hi = nums.size() - 1;
            while(lo < hi)
            {
                int mid = (hi + lo) / 2;
                if(nums[mid] > nums[hi])
                {
                    lo = mid + 1;
                }
                else
                {
                    hi = mid;
                }
            }
            lowest = lo;
        }
        if(nums[lowest] == target)
        {
            answer = lowest;
            return answer;
        }
        int hi, lo;
        lo = (target <= nums[nums.size() - 1]) ? lowest : 0;
        hi = (target <= nums[nums.size() - 1]) ? nums.size()-1: lowest-1;
        while(lo <= hi)
        {
            int mid = (hi + lo) / 2;
            if(nums[mid] < target)
            {
                lo = mid + 1;
            }
            else if (nums[mid] > target)
            {
                hi = mid - 1;
            }
            else
            {
                answer = mid;
                break;
            }
        }
        return answer;
    }
};