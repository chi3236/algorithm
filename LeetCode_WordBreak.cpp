class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int memo[s.length()+1] = {0,};
        memo[0] = 1;
        for(int i = 1; i <= s.length(); i++)
        {
            for(int j = i-1; j >= 0; j--)
            {
                if(memo[j] == 1)
                {
                    if(find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end())
                    {
                        memo[i] = 1;
                        break;
                    }
                }
            }
        }
        return memo[s.length()] == 1;
    }
};