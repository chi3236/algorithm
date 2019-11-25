class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> memo(n+1, 0);
        memo[n] = 1;
        for(int i = n-1; i >= 0; i--)
        {
            if(s[i] == '0')
            {
                memo[i] = 0;
            }
            else if(s[i] == '1')
            {
                if(i == n-1)
                {
                    memo[i] = memo[i+1];
                }
                else
                {
                    memo[i] = memo[i+1] + memo[i+2];
                }
            }
            else if(s[i] == '2')
            {
                if(s[i+1] >= '0' && s[i+1] <= '6')
                {
                    if(i == n-1)
                    {
                        memo[i] = memo[i+1];
                    }
                    else
                    {
                        memo[i] = memo[i+1] + memo[i+2];
                    }
                    
                }
                else
                {
                    memo[i] = memo[i+1];
                }
            }
            else
            {
                memo[i] = memo[i+1];
            }
        }
        return memo[0];
    }
};
