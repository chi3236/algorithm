class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty())
        {
            return 0;
        }
        int answer = 0;
        vector<int> memo(s.size(), 0);
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i] == ')')
            {
                if(s[i-1] == '(')
                {
                    if(i < 2)
                    {
                        memo[i] = 2;
                    }
                    else
                    {
                        memo[i] = memo[i - 2] + 2;
                    }
                }
                else
                {
                    if(i - memo[i-1] > 0 && s[i - memo[i-1] - 1] == '(')
                    {
                        if(i - memo[i-1] < 2)
                        {
                            memo[i] =  memo[i-1] + 2;
                        }
                        else
                        {
                            memo[i] = memo[i-1] + memo[i - memo[i-1] - 2] + 2;
                        }
                    }
                }
                answer = max(answer, memo[i]);
            }
        }
        return answer;
    }
};