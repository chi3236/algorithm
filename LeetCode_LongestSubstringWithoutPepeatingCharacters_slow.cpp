class Solution {
public:
    struct alphabet
    {
        char c;
        int index;
    };
    int lengthOfLongestSubstring(string s) {
        //a = 97
        if(s.length() == 0)
        {
            return 0;
        }
        vector<struct alphabet> alphabetInit(127);
        for(int i = 0; i < alphabetInit.size(); i++)
        {
            alphabetInit[i].c = 0;
            alphabetInit[i].index = -1;
        }
        vector<struct alphabet> currAlpha = alphabetInit;
        int answer = -1;
        int count = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(currAlpha[(int)s[i]].c == 0)
            {
                currAlpha[(int)s[i]].c = 1;
                currAlpha[(int)s[i]].index = i;
                count++;
            }
            else
            {
                if(answer < count)
                {
                    answer = count;
                }
                if(s[i] == s[i - 1])
                {
                    currAlpha = alphabetInit;
                    count = 1;
                    currAlpha[(int)s[i]].index = i;
                    currAlpha[(int)s[i]].c = 1;
                }
                else
                {
                    count = i - currAlpha[(int)s[i]].index;
                    for(int j = currAlpha[(int)s[i]].index - 1; j >= 0; j--)
                    {
                        if(currAlpha[(int)s[j]].index <= j)
                        {
                            currAlpha[(int)s[j]].c = 0;
                            currAlpha[(int)s[j]].index = -1;  
                        }  
                    }
                    currAlpha[(int)s[i]].index = i;
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