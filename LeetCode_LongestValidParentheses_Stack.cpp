class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty())
        {
            return 0;
        }
        int answer = 0;
        stack<int> count;
        count.push(-1);
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                count.push(i);
            }
            else
            {
                count.pop();
                if(count.empty())
                {
                    count.push(i);
                }
                else
                {
                    answer = max(answer, i - count.top());
                }
            }
        }
        return answer;
    }
};