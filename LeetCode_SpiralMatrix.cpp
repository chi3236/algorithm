class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;
        if(matrix.empty())
        {
            return answer;
        }
        int r_n = matrix.size();
        int c_n = matrix[0].size();
        vector<vector<int>> visited;
        visited.assign(r_n, vector<int>(c_n, 0));
        int i = 0;
        int j = 0;
        int direction = 0;
        while(i >= 0 && i < r_n && j>=0 && j < c_n && visited[i][j] == 0)
        {
            if(direction == 0)
            {
                while(j < c_n && visited[i][j] == 0)
                {
                    answer.push_back(matrix[i][j]);
                    visited[i][j++] = 1;
                }
                j--;
                i++;
            }
            else if(direction == 1)
            {
                while(i < r_n && visited[i][j] == 0)
                {
                    answer.push_back(matrix[i][j]);
                    visited[i++][j] = 1;
                }
                i--;
                j--;
            }
            else if(direction == 2)
            {
                while(j >= 0 && visited[i][j] == 0)
                {
                    answer.push_back(matrix[i][j]);
                    visited[i][j--] = 1;
                }
                j++;
                i--;
            }
            else
            {
                while(i >= 0 && visited[i][j] == 0)
                {
                    answer.push_back(matrix[i][j]);
                    visited[i--][j] = 1;
                }
                i++;
                j++;
            }
            direction = (direction + 1) % 4;
        }
        return answer;
    }
};
