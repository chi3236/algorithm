class Solution {
public:
    int myAtoi(string str) {
        long long answer = 0;
        if(str.length() == 0)
        {
            return answer;
        }
        string number;
        bool first = false;
        bool firstNum = false;
        bool minus = false;
        for(int i = 0; i < str.length(); i++)
        {
            if(!isdigit(str[i]))
            {
                if(str[i] == '+')
                {
                    if(!first)
                    {
                       first = true;
                    }
                    else
                    {
                       break;
                    } 
                }
                else if(str[i] == '-')
                {
                    if(!first)
                    {
                        first = true;
                        minus = true;
                    }
                    else
                    {
                       break;
                    }
                }
                else if(str[i] == ' ')
                {
                    if(!first)
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            else
            {
                if(str[i] == '0')
                {
                    if(first && firstNum)
                    {
                        number.push_back(str[i]);
                    }
                    else if(!first || !firstNum)
                    {
                        if(i < str.length() - 1 && !isdigit(str[i + 1]))
                        {
                            return 0;
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
                else
                {
                    first = true;
                    firstNum = true;
                    number.push_back(str[i]);
                }
            }
        }
        if(number.length() != 0)
        {
            if(number.length() >= 11)
            {
                if(minus)
                {
                    return INT_MIN;
                }
                else
                {
                    return INT_MAX;
                }
            }
            else
            {
                long long tenPow = pow(10, number.length() - 1);
                for(int i = 0; i < number.length(); i++)
                {
                    answer += ((long long)number[i] - 48) * tenPow;
                    tenPow /= 10;
                }
            }
        }
        if(minus)
        {
            answer *= -1;
        }
        if(answer <= INT_MIN)
        {
            return INT_MIN;
        }
        if(answer >= INT_MAX)
        {
            return INT_MAX;
        }
        return answer;
    }
};