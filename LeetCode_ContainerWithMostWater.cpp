class Solution {
public:
    int maxArea(vector<int>& height) {
        int answer = 0;
        if(height.empty())
        {
            return answer;
        }
        int i = 0;
        int j = height.size() - 1;
        while(i < j)
        {
            int minHeight = min(height[i], height[j]);
            int curr = (j - i) * minHeight;
            if(answer < curr)
            {
                answer = curr;
            }
            while(height[j] <= minHeight && i < j)
            {
                j--;
            }
            while(height[i] <= minHeight && i < j)
            {
                i++;
            }
        }
        return answer;
    }
};