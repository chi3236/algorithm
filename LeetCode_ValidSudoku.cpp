class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //check row
        for(int i = 0; i < 9; i++)
        {
            map<char, int> hash;
            for(int j = 0; j < 9; j++)
            {
                if(board[j][i] != '.')
                {
                    if(hash.find(board[j][i]) != hash.end())
                    {
                        return false;
                    }
                    else
                    {
                        hash[board[j][i]] == 1;
                    }
                }
            }
        }
        //check col
        for(int i = 0; i < 9; i++)
        {
            map<char, int> hash;
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    if(hash.find(board[i][j]) != hash.end())
                    {
                        return false;
                    }
                    else
                    {
                        hash[board[i][j]] == 1;
                    } 
                }
            }
        }
        //check each box
        for(int i = 0; i < 9; i=i+3)
        {
            for(int j = 0; j < 9; j=j+3)
            {
                map<char, int> hash;
                for(int k = i; k < i+3; k++)
                { 
                    for(int l = j; l < j+3; l++)
                    {
                        if(board[k][l] != '.')
                        {
                            if(hash.find(board[k][l]) != hash.end())
                            {
                                return false;
                            }
                            else
                            {
                                hash[board[k][l]] == 1;
                            } 
                        }
                    }
                }
            }
        }
        return true;
    }
};