class Solution {
public:
    vector<vector<int>> memory;
    bool isMatch(string s, string p) {
        memory.assign(s.length() + 1, vector<int>(p.length() + 1, -1));
        return dp(0, 0, s, p);
    }
    
    bool dp(int i, int j, string s, string p)
    {
        if(memory[i][j] != -1)
        {
            if(memory[i][j] == 0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        bool answer;
        if(j == p.length())
        {
            answer = (i == s.length()); 
        }
        else
        {
            bool firstMatch;
            firstMatch = (i < s.length() && (s[i] == p[j] || p[j] == '.'));
            if(j + 1 < p.length() && p[j + 1] == '*')
            {
                answer = dp(i, j + 2, s, p) || (firstMatch && dp(i + 1, j, s, p));
            }
            else
            {
                answer = firstMatch && dp(i + 1, j + 1, s, p);
            }
        }
        if(!answer)
        {
            memory[i][j] = 0;
        }
        else
        {
            memory[i][j] = 1;
        }
        return answer;
    }
};