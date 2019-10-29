class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        if(strs.empty())
        {
            return answer;
        }
        int n = strs.size();
        map<vector<int>, int> hash;
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            vector<int> charCount(26, 0);
            for(int j = 0; j < strs[i].length(); j++)
            {
                charCount[strs[i][j] - 'a']++;
            }
            if(hash.find(charCount) != hash.end())
            {
                answer[hash[charCount]].push_back(strs[i]);
            }
            else
            {
                hash[charCount] = count++;
                vector<string> strings(1, strs[i]);
                answer.push_back(strings);
            }
        }
        return answer;
    }
};
