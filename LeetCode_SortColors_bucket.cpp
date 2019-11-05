class Solution {
public:
    void sortColors(vector<int>& nums) {
        int bucket[3] = {0,};
        for(int i = 0; i < nums.size(); i++)
        {
            bucket[nums[i]]++;
        }
        int i = 0;
        for(int j = 0; j < 3; j++)
        {
            while(bucket[j] > 0)
            {
                nums[i++] = j;
                bucket[j]--;
            }
        }
    }
};
