class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty())
        {
            return 0;
        }
        int answer = 0;
        int n = heights.size();
        int leftShortIdx[n] = {0,};
        int rightShortIdx[n] = {0,};
        leftShortIdx[0] = -1;
        rightShortIdx[n-1] = n;
        for(int i = 1; i < n; i++)
        {
            int j = i - 1;
            while(j >= 0 && heights[j] >= heights[i])
            {
                j = leftShortIdx[j];
            }
            leftShortIdx[i] = j;
        }
        for(int i = n - 2; i >= 0; i--)
        {
            int j = i + 1;
            while(j < n && heights[j] >= heights[i])
            {
                j = rightShortIdx[j];
            }
            rightShortIdx[i] = j;
        }
        for(int i = 0; i < n; i++)
        {
            answer = max(answer, (rightShortIdx[i] - leftShortIdx[i] - 1) * heights[i]);
        }
        return answer;
    }
};
