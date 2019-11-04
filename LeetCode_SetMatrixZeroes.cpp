class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty())
        {
            return;
        }
        bool firstCol = false;
        int r_n = matrix.size();
        int c_n = matrix[0].size();
        for(int i = 0; i < r_n; i++)
        {
            if(matrix[i][0] == 0)
            {
                firstCol = true;
            }
            for(int j = 1; j < c_n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < r_n; i++)
        {
            for(int j = 1; j < c_n; j++)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if(matrix[0][0] == 0)
        {
            for(int j = 0; j < c_n; j++)
            {
                matrix[0][j] = 0;
            }
        }
        if(firstCol)
        {
            for(int i = 0; i < r_n; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};
