class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;
        if(numRows == 0)
        {
            return answer;
        }
        vector<int> currRow(1, 1);
        answer.push_back(currRow);
        int currIndex = 1;
        while(currIndex < numRows)
        {
            vector<int> currRow;
            for(int i = 0; i < currIndex + 1; i++)
            {
                if(i == 0 || i == currIndex)
                {
                    currRow.push_back(1);
                }
                else
                {
                    currRow.push_back(answer[currIndex-1][i-1] + answer[currIndex-1][i]);
                }
            }
            answer.push_back(currRow);
            currIndex++;
        }
        return answer;
    }
};
