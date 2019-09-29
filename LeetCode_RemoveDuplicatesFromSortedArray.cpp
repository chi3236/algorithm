class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }
        int count = 0;
        int temp = nums[0];
        int i = 1;
        int j = 1;
        while(i < nums.size())
        {
            if(nums[i] == temp)
            {
                count++;
            }
            else
            {
                temp = nums[i];
                nums[j++] = nums[i];
            }
            i++;
        }
        return nums.size()-count;
    }
};