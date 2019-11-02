class Solution {
public:
    
    static bool compare (vector<int>& a, vector<int>& b)
    {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> answer;
        if(intervals.empty())
        {
            return answer;
        }
        sort(intervals.begin(), intervals.end(), compare);
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] > end)
            {
                vector<int> merged;
                merged.push_back(start);
                merged.push_back(end);
                answer.push_back(merged);
                start = intervals[i][0];
                end = intervals[i][1];
            }
            else
            {
                if(end < intervals[i][1])
                {
                    end = intervals[i][1];
                }
            }
        }
        vector<int> merged;
        merged.push_back(start);
        merged.push_back(end);
        answer.push_back(merged);
        return answer;
    }
};