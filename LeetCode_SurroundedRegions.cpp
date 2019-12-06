class Solution {
public:
    struct coor
    {
        int y;
        int x;
    };
    void solve(vector<vector<char>>& board) {
        if(board.empty())
        {
            return;
        }
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {-1, 0, 1, 0};
        int yn = board.size();
        int xn = board[0].size();
        vector<struct coor> vec;
        int visited[yn][xn] = {0,};
        for(int i = 0; i < yn; i++)
        {
            for(int j = 0; j < xn; j++)
            {
                if(i == 0 || j == 0 || i == yn-1 || j == xn-1)
                {
                    if(board[i][j] == 'O')
                    {
                        visited[i][j] = -1;
                    }
                }
                if(board[i][j] == 'X')
                {
                    visited[i][j] = 1;
                }
            }
        }
        for(int i = 1; i < yn-1; i++)
        {
            for(int j = 1; j < xn-1; j++)
            {
                if(board[i][j] == 'O' && visited[i][j] == 0)
                {
                    queue<struct coor> q;
                    visited[i][j] = 1;
                    struct coor c{i, j};
                    q.push(c);
                    vector<struct coor> vec;
                    bool save = true;
                    while(!q.empty())
                    {
                        struct coor curr = q.front();
                        q.pop();
                        if(save)
                        {
                            vec.push_back(curr);
                        }
                        for(int k = 0; k < 4; k++)
                        {
                            if(board[curr.y + dy[k]][curr.x + dx[k]] == 'O')
                            {
                                if(visited[curr.y + dy[k]][curr.x + dx[k]] == 0)
                                {
                                    struct coor next{curr.y + dy[k], curr.x + dx[k]};
                                    visited[next.y][next.x] = 1;
                                    q.push(next);
                                }
                                else if(visited[curr.y + dy[k]][curr.x + dx[k]] == -1)
                                {
                                    save = false;
                                }
                            }
                        }
                    }
                    if(save)
                    {
                        for(int k = 0; k < vec.size(); k++)
                        {
                            board[vec[k].y][vec[k].x] = 'X';
                        } 
                    }
                }
            }
        }
    }
};