class Solution {
public:
    bool check(string& s)
    {
        int front = 0;
        int rear = s.length()-1;
        while(front < rear)
        {
            if(s[front++] != s[rear--])
            {
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> answer;
    
    void helper(string& s, vector<string>& strings, int start)
    {
        if(start >= s.length())
        {
            answer.push_back(strings);
            return;
        }
        for(int i = 1; i <= s.length() - start; i++)
        {
            string sub = s.substr(start, i);
            if(check(sub))
            {
                strings.push_back(sub);
                helper(s, strings, start+i);
                strings.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        if(s.empty())
        {
            return vector<vector<string>>();
        }
        vector<string> strings;
        helper(s, strings, 0);
        return answer;
    }
};