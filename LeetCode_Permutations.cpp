class Solution {
public:
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> first;
        for(int i = 0; i < nums.size(); i++)
        {
            first.push_back(nums[i]);
        }
        if(nums.empty())
        {
            return answer;
        }
        int n = nums.size();
        while(true)
        {
            answer.push_back(nums);
            int pivot = 0;
            bool breaked = false;
            for(int i = n - 1; i > 0; i--)
            {
                if(nums[i] > nums[i-1])
                {
                    pivot = i-1;
                    breaked = true;
                    break;
                }
            }
            if(pivot == 0 && !breaked)
            {
                for(int i = 0; i <= (n-1)/2; i++)
                {
                    swap(nums[i], nums[n-1-i]);
                }
            }
            else
            {
                int min = 987654321;
                int minIndex;
                for(int i = pivot + 1; i < n; i++)
                {
                    if(nums[i] <= min && nums[i] > nums[pivot])
                    {
                        min = nums[i];
                        minIndex = i;
                    }
                }
                swap(nums[pivot], nums[minIndex]);
                for(int i = pivot+1; i <= pivot + (n-1-pivot)/2; i++)
                {
                    swap(nums[i], nums[n-1-(i-(pivot+1))]);
                }
            }
            if(nums == first)
            {
                break;
            }
        }
        return answer;
    }
};
