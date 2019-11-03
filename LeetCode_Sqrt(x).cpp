class Solution {
public:
    int mySqrt(int x) {
        double answer = 1;
        for(int i = 0; i < 20; i++)
        {
            double curr = (answer + x/answer) / 2;
            if(curr == answer)
            {
                break;
            }
            else
            {
                answer = curr;
            }
        }
        return (int)answer;
    }
};