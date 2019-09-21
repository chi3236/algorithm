class Solution {
public:
    vector<string> letters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        if(digits.empty())
        {
            return answer;
        }
        making(digits, 0, answer, "");
        return answer;
    }
    
    void making(string digits, int index, vector<string>& answer, string prev)
    {
        if(index >= digits.length())
        {
            answer.push_back(prev);
            return;
        }
        for(int i = 0; i < letters[(digits[index] - '0') - 2].length(); i++)
        {
            string curr = prev;
            curr.push_back(letters[(digits[index] - '0') - 2][i]);
            making(digits, index + 1, answer, curr);
            curr.pop_back();
        }
    }
};