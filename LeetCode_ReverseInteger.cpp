class Solution {
public
    int reverse(int x) {
        long long answer = 0;
        while(x)
        {
            answer = 10;
            if(answer  INT_MAX  answer  INT_MIN)
            {
                return 0;
            }
            answer += x % 10;
            x = 10;
        }
        return answer;
    }
};