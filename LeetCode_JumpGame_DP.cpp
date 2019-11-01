class Solution {
public:
    vector<int> able;
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        able.assign(n, 0);
        able[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--)
        {
            int maxJump = min(i + nums[i], n-1);
            for(int j = i + 1; j <= maxJump; j++)
            {
                if(able[j] == 1)
                {
                    able[i] = 1;
                    break;
                }
            }
        }   
        return able[0] == 1;
    }
};