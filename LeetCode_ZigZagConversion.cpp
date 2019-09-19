class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
        {
            return s;
        }
        string answer;
        int interval = (numRows-1) * 2;
        for(int i = 0; i < numRows; i++)
        {
            int j = i;
            int first = interval - (2 * i);
            int last = interval - first;
            answer.push_back(s[j]);
            while(true)
            {
                if(first != 0)
                {
                    j += first;
                    if(j >= s.length())
                    {
                        break;
                    }
                    answer.push_back(s[j]);
                }
                if(last != 0)
                {
                    j += last;
                    if(j >= s.length())
                    {
                        break;
                    }
                    answer.push_back(s[j]);
                }
            }
        }
        return answer;
    }
};