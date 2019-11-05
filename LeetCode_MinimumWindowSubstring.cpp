class Solution {
public:
    string minWindow(string s, string t) {
        string answer;
        if(s.empty() || t.empty())
        {
            return answer;
        }
        int minLen = INT_MAX;
        int minStart = 0;
        unordered_map<char, int> hash;
        for(int i = 0; i < t.length(); i++)
        {
            hash[t[i]]++;
        }
        int start = 0;
        int end = 0;
        int count = t.length();
        while(end < s.length())
        {
            if(hash[s[end]] > 0)
            {
                count--;
            }
            hash[s[end]]--;
            end++;
            while(count == 0)
            {
                if(end - start < minLen)
                {
                    minLen = end - start;
                    minStart = start;
                }
                hash[s[start]]++;
                if(hash[s[start]] > 0)
                {
                    count++;
                }
                start++;
            }
        }
        if(minLen != INT_MAX)
        {
            answer = s.substr(minStart, minLen);
        }
        return answer;
    }
};