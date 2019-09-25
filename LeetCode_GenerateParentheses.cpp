class Solution {
public:
    vector<string> answer;
    vector<string> generateParenthesis(int n) {
        if(n == 0)
        {
            return vector<string>();
        }
        DFS(n, "", 0, 0, 2*n);
        return answer;
    }
    void DFS(int n, string par, int l, int r, int max)
    {
        if(par.length() == max)
        {
            answer.push_back(par);
            return;
        }
        if(l < n)
        {
            DFS(n, par+'(', l+1, r, max);
        }
        if(l > r)
        {
            DFS(n, par+')', l, r+1, max);
        }
    }