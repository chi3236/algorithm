class Solution {
public:
    bool check(string& w1, string& w2)
    {
        int same = 0;
        int l = w1.length();
        for(int i = 0; i < l; i++)
        {
            if(w1[i] == w2[i])
            {
                same++;
            }
        }
        return same == (l - 1);
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end())
        {
            return 0;
        }
        unordered_set newWordList(wordList.begin(), wordList.end());
        queue<string> q;
        int level = 1;
        q.push(beginWord);
        while(!q.empty())
        {
            for(int i = q.size(); i > 0; i--)
            {
                string curr = q.front();
                q.pop();
                if(curr == endWord)
                {
                    return level;
                }
                for(int j = 0; j < beginWord.length(); j++)
                {
                    char c = curr[j];
                    for(int k = 0; k < 26; k++)
                    {
                        curr[j] = 'a' + k;
                        if(newWordList.find(curr) != newWordList.end())
                        {
                            q.push(curr);
                            newWordList.erase(curr);
                        }
                    }
                    curr[j] = c;
                }
            }
            level++;
        }
        return 0;
    }
};