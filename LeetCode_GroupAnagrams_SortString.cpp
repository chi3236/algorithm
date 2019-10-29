class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        if(strs.empty())
        {
            return answer;
        }
        int n = strs.size();
        unordered_map<string, int> hash;
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if(hash.find(temp) != hash.end())
            {
                answer[hash[temp]].push_back(strs[i]);
            }
            else
            {
                hash[temp] = count++;
                vector<string> strings;
                strings.push_back(strs[i]);
                answer.push_back(strings);
            }
        }
        return answer;
    }
};
