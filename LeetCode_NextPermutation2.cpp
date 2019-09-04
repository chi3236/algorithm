class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int boundary = 0;
        bool breaked = false;
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                boundary = i;
                breaked = true;
                break;
            }
        }
        if(boundary == 0 && !breaked)
        {
            for(int i = 0; i <= (nums.size()-1)/2; i++)
            {
                int temp = nums[i];
                nums[i] = nums[nums.size()-1-i];
                nums[nums.size()-1-i] = temp;
            }
        }
        else
        {
            int minNum = 987654321;
            int minIndex = 0;
            for(int i = boundary + 1; i < nums.size(); i++)
            {
                if(nums[i] <= minNum && nums[i] > nums[boundary])
                {
                    minNum = nums[i];
                    minIndex = i;
                }
            }
            int temp = nums[boundary];
            nums[boundary] = nums[minIndex];
            nums[minIndex] = temp;
            for(int i = boundary + 1; i <= boundary + (nums.size()-1 - boundary)/2; i++)
            {
                int temp = nums[i];
                nums[i] = nums[nums.size()-1-(i-(boundary+1))];
                nums[nums.size()-1-(i-(boundary+1))] = temp;
            }
        }
    }
};