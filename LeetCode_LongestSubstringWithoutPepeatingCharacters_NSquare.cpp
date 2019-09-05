class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //a = 97
        if(s.length() == 0)
        {
            return 0;
        }
        vector<int> alphabetInit(127, 0);
        vector<int> currAlpha = alphabetInit;
        int answer = -1;
        int count = 0;
        for(int i = 0; i < s.length(); i++)
        {
            for(int j = i; j < s.length(); j++)
            {
                if(currAlpha[(int)s[j]] == 0)
                {
                    currAlpha[(int)s[j]] = 1;
                    count++;
                }
                else
                {
                    break;
                }
            }
            if(answer < count)
            {
                answer = count;
            }
            currAlpha = alphabetInit;
            count = 0;
        }
        return answer;
    }
};