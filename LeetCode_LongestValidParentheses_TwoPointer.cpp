class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty())
        {
            return 0;
        }
        int answer = 0;
        int left = 0;
        int right = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                left++;
            }
            else
            {
                right++;
            }
            if(left == right)
            {
                answer = max(answer, left*2);
            }
            else if(left < right)
            {
                left = right = 0;
            }
        }
        left = 0;
        right = 0;
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if(s[i] == ')')
            {
                right++;
            }
            else
            {
                left++;
            }
            if(left == right)
            {
                answer = max(answer, left*2);
            }
            else if(left > right)
            {
                left = right = 0;
            }
        }
        return answer;
    }
};