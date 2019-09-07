class Solution {
public:
    int romanToInt(string s) {
        map<char, int> table = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int i = 0;
        int answer = 0;
        while(i < s.length())
        {
            if(s[i] == 'I')
            {
                if((s[i + 1] == 'V' || s[i + 1] == 'X') && i + 1 < s.length())
                {
                    answer += table[s[i + 1]] - table[s[i]];
                    i++;
                }
                else
                {
                    answer += table[s[i]];
                }
            }
            else if(s[i] == 'X')
            {
                if((s[i + 1] == 'L' || s[i + 1] == 'C') && i + 1 < s.length())
                {
                    answer += table[s[i + 1]] - table[s[i]];
                    i++;
                }
                else
                {
                    answer += table[s[i]];
                }
            }
            else if(s[i] == 'C')
            {
                if((s[i + 1] == 'D' || s[i + 1] == 'M') && i + 1 < s.length())
                {
                    answer += table[s[i + 1]] - table[s[i]];
                    i++;
                }
                else
                {
                    answer += table[s[i]];
                }
            }
            else
            {
                answer += table[s[i]];
            }
            i++;
        }
        return answer;
    }
};