class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        if(nums.empty())
        {
            return answer;
        }
        sort(nums.begin(), nums.end());
        answer.push_back(nums);
        while(next_permutation(nums.begin(), nums.end()))
        {
            answer.push_back(nums);
        }
        return answer;
    }
};
