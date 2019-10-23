class Solution {
public:
    int trap(vector<int>& height) {
        int answer = 0;
        if(height.empty())
        {
            return answer;
        }
        int n = height.size();
        int lo = 0;
        int hi = n - 1;
        int leftMax = 0;
        int rightMax = 0;
        while(lo < hi)
        {
            if(height[lo] < height[hi])
            {
                if(height[lo] < leftMax)
                {
                    answer += leftMax - height[lo];
                }
                else
                {
                    leftMax = height[lo];
                }
                lo++;
            }
            else
            {
                if(height[hi] < rightMax)
                {
                    answer += rightMax - height[hi];
                }
                else
                {
                    rightMax = height[hi];
                }
                hi--;
            }
        }
        return answer;
    }
};
