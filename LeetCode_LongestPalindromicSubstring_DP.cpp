class Solution {
public:
    string longestPalindrome(string s) {
        string answer;
        if(s.length() == 0)
        {
            return answer;
        }
        answer.push_back(s[0]);
        for(int i = 0; i < s.length(); i++)
        {
            //odd
            int l = i - 1;
            int r = i + 1;
            int lf = i, rf = i;
            while(l >= 0 && r < s.length())
            {
                if(s[l] == s[r])
                {
                    lf = l;
                    rf = r;
                }
                else
                {
                    break;
                }
                l--;
                r++;
            }
            if(rf-lf+1 > answer.length())
            {
                answer = s.substr(lf, rf-lf + 1);
            }
            //even
            if(s[i] == s[i + 1])
            {
                int l = i - 1;
                int r = i + 2;
                int lf = i;
                int rf = i + 1;
                while(l >= 0 && r < s.length())
                {
                    if(s[l] == s[r])
                    {
                        lf = l;
                        rf = r;
                    }
                    else
                    {
                        break;
                    }
                    l--;
                    r++;
                }
                if(rf-lf + 1 > answer.length())
                {
                    answer = s.substr(lf, rf-lf + 1);
                }
            }
        }
        return answer;
    }
};
