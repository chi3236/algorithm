class Solution {
public:
    
    void DFS(vector<int>& memo, vector<string>& answer, string s, vector<string>& wordDict, string curr, int start, int end)
    {
        if(end >= s.length())
        {
            if(memo[s.length()] == 1)
            {
                answer.push_back(curr);
            }
        }
        for(int i = end; i <= s.length(); i++)
        {
            for(int j = i-1; j >= start; j--)
            {
                if(memo[j] == 1)
                {
                    string sub = s.substr(j, i-j);
                    if(find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end())
                    {
                        memo[i] = 1;
                        string next = curr;
                        if(curr.length() == 0)
                        {
                            next.append(sub);
                        }
                        else
                        {
                            next.append(" ");
                            next.append(sub);
                        }
                        DFS(memo, answer, s, wordDict, next, j+1, i+1);
                        memo[i] = 0;
                        break;
                    }
                }
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int canBreak[s.length()+1] = {0,};
        canBreak[0] = 1;
        for(int i = 1; i <= s.length(); i++)
        {
            for(int j = i-1; j >= 0; j--)
            {
                if(canBreak[j] == 1)
                {
                    if(find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end())
                    {
                        canBreak[i] = 1;
                        break;
                    }
                }
            }
        }
        if(canBreak[s.length()] == 0)
        {
            return vector<string>();
        }
        vector<int> memo(s.length()+1, 0);
        memo[0] = 1;
        vector<string> answer;
        string curr;
        DFS(memo, answer, s, wordDict, curr, 0, 1);
        return answer;
    }
};