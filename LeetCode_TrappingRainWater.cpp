class Solution {
public:
    int trap(vector<int>& height) {
        int answer = 0;
        if(height.empty())
        {
            return answer;
        }
        int n = height.size();
        vector<int> leftMax(n, 0);
        vector<int> rightMax(n ,0);
        leftMax[0] = height[0];
        for(int i = 1; i < n; i++)
        {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        rightMax[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--)
        {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        for(int i = 0; i < n; i++)
        {
            answer += (min(leftMax[i], rightMax[i]) - height[i]);
        }
        return answer;
    }
};
