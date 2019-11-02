class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 0 || n == 0)
        {
            return 0;
        }
        vector<int> prev(n, 1);
        vector<int> curr(n, 0);
        curr[0] = 1;
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                curr[j] = prev[j] + curr[j-1];
            }
            swap(prev, curr);
        }
        return prev[n-1];
    }
};