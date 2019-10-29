class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
        {
            return 1;
        }
        else if (n == 1)
        {
            return x;
        }
        else if (n == -1)
        {
            return 1/x;
        }
        else
        {
            if(n % 2 == 0)
            {
                return pow(x, n/2) * pow(x, n/2);
            }
            else
            {
                return x * pow(x, (n-1));
            }
        }
    }
};
