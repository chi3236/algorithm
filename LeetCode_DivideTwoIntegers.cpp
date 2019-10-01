class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == -1 && dividend == INT_MIN)
        {
            return INT_MAX;
        }
        if(divisor == 1)
        {
            return dividend;
        }
        int sign = 1;
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
        {
            sign = -1;
        }
        long long dvd;
        long long dvs;
        if(dividend < 0)
            dvd = dividend * (long long)-1;
        else
            dvd = dividend;
        if(divisor < 0)
            dvs = divisor * (long long)-1;
        else
            dvs = divisor;

        if(dvd < dvs)
        {
            return 0;
        }
        int answer = 0;
        while(dvd >= dvs)
        {
            int count = 1;
            long long currDvs = dvs;
            while((currDvs << 1) <= dvd)
            {
                currDvs = currDvs << 1;
                count += count;
            }
            dvd -= currDvs;
            answer += count;
        }
        return answer * sign;
    }
};