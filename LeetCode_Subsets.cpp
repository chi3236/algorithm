class Solution {
public:
    vector<vector<int>> answer;
    void DFS(vector<int> nums, vector<int>& list, int start, int currSize, int targetSize)
    {
        if(currSize == targetSize)
        {
            answer.push_back(list);
            return;
        }
        for(int i = start; i < nums.size(); i++)
        {
            list.push_back(nums[i]);
            DFS(nums, list, i+1, currSize + 1, targetSize);
            list.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty())
        {
            vector<int> subsetList;
            answer.push_back(subsetList);
            return answer;
        }
        vector<int> subsetList;
        for(int i = 0; i <= nums.size(); i++)
        {
           DFS(nums, subsetList, 0, 0, i);
        }
        return answer;
    }
};
