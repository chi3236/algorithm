class Solution {
public:
    string longestPalindrome(string s) {
        string answer;
        if(s.length() == 0)
        {
            return answer;
        }
        if(s.length() == 1)
        {
            return s;
        }
        for(int i = s.length(); i >= 2; i--)
        {
            for(int j = 0; j <= s.length() - i; j++)
            {
                bool isPalindrome = true;
                int back = 0;
                for(int k = j; k < j + i/2; k++)
                {
                    if(s[k] != s[(j + i - 1) - back])
                    {
                        isPalindrome = false;
                        break;
                    }
                    back++;
                }
                if(isPalindrome)
                {
                    return s.substr(j, i);
                }
            }
        }
        answer = s[0];
        return answer;
    }
};