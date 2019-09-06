class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
        {
            return 0;
        }
        int alphabet[128];
        fill_n(alphabet, 128, -1);
        int answer = -1;
        int count = 0;
        int startPoint = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(alphabet[(int)s[i]] == -1)
            {
                alphabet[(int)s[i]] = i;
                count++;
            }
            else
            {
                if(alphabet[(int)s[i]] < startPoint)
                {
                    alphabet[(int)s[i]] = i;
                    count++;
                }
                else
                {
                    if(answer < count)
                    {
                        answer = count;
                    }
                    count = i - alphabet[(int)s[i]];
                    startPoint = alphabet[(int)s[i]] + 1;
                    alphabet[(int)s[i]] = i;
                } 
            }
        }
        if(answer < count)
        {
            answer = count;
        }
        return answer;
    }
};