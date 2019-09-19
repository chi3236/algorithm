class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer;
        if(strs.size() == 0)
        {
            return answer;
        }
        sort(strs.begin(), strs.end());
        for(int i = 0; i < strs[0].length(); i++)
        {
            bool match = true;
            char curr = strs[0][i];
            for(int j = 1; j < strs.size(); j++)
            {
                if(curr != strs[j][i])
                {
                    match = false;
                    break;
                }
            }
            if(match)
            {
                answer.push_back(curr);
            }
            else
            {
                break;
            }
        }
        return answer;
    }
};