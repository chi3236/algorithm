class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty())
        {
            return 0;
        }
        int answer = 0;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        int n = heights.size();
        stack<int> s;
        s.push(0);
        for(int i = 1; i < n; i++)
        {
            while(heights[i] < heights[s.top()])
            {
                int right = s.top();
                s.pop();
                answer = max(answer, (i - s.top() - 1) * heights[right]);
            }
            s.push(i);
        }
        return answer;
    }
};
