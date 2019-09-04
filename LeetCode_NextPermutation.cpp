class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int boundary = 0;
        bool breaked = false;
        for(int i = nums.size() - 1; i > 0; i--)
        {
            if(nums[i] > nums[i-1])
            {
                breaked = true;
                boundary = i - 1;
                break;
            }
        }
        if(boundary == 0 && !breaked)
            sort(nums.begin(), nums.end());
        else
        {
            int minNum = 987654321;
            int minIndex = 0;
            for(int i = boundary + 1; i < nums.size(); i++)
            {
                if(nums[i] < minNum && nums[i] > nums[boundary])
                {
                    minNum = nums[i];
                    minIndex = i;
                }
            }
            int temp = nums[boundary];
            nums[boundary] = nums[minIndex];
            nums[minIndex] = temp;
            sort(nums.begin() + boundary + 1, nums.end());
        }
    }
};