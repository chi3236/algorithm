class Solution {
public:
    void DFS(vector<int>& candidates, int target, int curr, int idx, vector<vector<int>>& ansList, vector<int>& ans)
    {
        if(curr == target)
        {
            ansList.push_back(ans);
        }
        else if(curr > target)
        {
            return;
        }
        else
        {
            for(int i = idx; i < candidates.size(); i++)
            {
                ans.push_back(candidates[i]);
                DFS(candidates, target, curr + candidates[i], i, ansList, ans);
                ans.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        if(candidates.empty())
        {
            return ans;
        }
        vector<int> list;
        DFS(candidates, target, 0, 0, ans, list);
        return ans;
    }
};
