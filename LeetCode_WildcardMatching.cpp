class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0;
        int j = 0;
        int match = 0;
        int star = -1;
        while(i < s.length())
        {
            if(j < p.length() && (p[j] == '?' || s[i] == p[j]))
            {
                i++;
                j++;
            }
            else if(j < p.length() && p[j] == '*')
            {
                star = j;
                match = i;
                j++;
            }
            else if(star != -1)
            {
                j = star + 1;
                i = ++match;
            }
            else
            {
                return false;
            }
        }
        while(j < p.length() && p[j] == '*')
        {
            j++;
        }
        return j == p.length();
    }
};