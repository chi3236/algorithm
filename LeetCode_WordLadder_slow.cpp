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
        queue<string> q;
        int visited[wordList.size()] = {0,};
        int level = 1;
        q.push(beginWord);
        while(!q.empty())
        {
            for(int j = q.size(); j > 0; j--)
            {
                string curr = q.front();
                q.pop();
                if(curr == endWord)
                {
                    return level;
                }
                for(int i = 0; i < wordList.size(); i++)
                {
                    if(visited[i] == 0 && check(curr, wordList[i]))
                    {
                        visited[i] = 1;
                        q.push(wordList[i]);
                    }   
                }
            }
            level++;
        }
        return 0;
    }
};