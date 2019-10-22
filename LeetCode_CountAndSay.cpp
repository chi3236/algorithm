class Solution {
public:
    string countAndSay(int n) {
        vector<int> nums(1, 1);
        while(--n)
        {
            vector<int> tempNums;
            int numCount = 0;
            for(int i = 0; i <= nums.size(); i++)
            {
                if(i == nums.size())
                {
                    tempNums.push_back(numCount);
                    tempNums.push_back(nums[i-1]);
                }
                else
                {
                    if(i == 0)
                    {
                        numCount++;
                    }
                    else
                    {
                        if(nums[i-1] != nums[i])
                        {
                            tempNums.push_back(numCount);
                            tempNums.push_back(nums[i-1]);
                            numCount = 1;
                        }
                        else
                        {
                            numCount++;
                        }
                    }
                }
            }
            nums=tempNums;
        }
        stringstream ss;
        for(int i = 0; i < nums.size(); i++)
        {
            ss << nums[i];
        }
        return ss.str();
    }
};
