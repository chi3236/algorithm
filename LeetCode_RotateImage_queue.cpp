class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n  == 0)
        {
            return;
        }
        queue<int> num;
        for(int i = 0; i < n; i++)
        {
            for(int j = n-1; j >= 0; j--)
            {
                num.push(matrix[j][i]);
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                matrix[i][j] = num.front();
                num.pop();
            }
        }
    }
};
