class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    
    bool DFS(vector<vector<char>> &board, string word, int y, int x, int wordIdx)
    {
        if(wordIdx == word.length() - 1)
        {
            if(board[y][x] == word[wordIdx])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        if(board[y][x] == word[wordIdx])
        {
            board[y][x] = NULL;
            for(int i = 0; i < 4; i++)
            {
                if(x + dx[i] >= 0 && x + dx[i] < board[y].size() && y + dy[i] >= 0 && y + dy[i] < board.size() && board[y + dy[i]][x + dx[i]] != NULL)
                {
                    if(DFS(board, word, y + dy[i], x + dx[i], wordIdx+1))
                    {
                        return true;
                    }
                }
            }
            board[y][x] = word[wordIdx];
        }
        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || word.empty())
        {
            return false;
        }
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                if(DFS(board, word, i, j, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
