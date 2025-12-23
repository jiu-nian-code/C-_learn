#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include<stack>

#include<string>

using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        stack<int> num;
        stack<int> start;
        string re;
        int k = 0;
        int loc = 0;
        int size = s.size();
        for (int i = 0; i < size; ++i)
        {
            int get = 0;
            if (s[i] >= '0' && s[i] <= '9')
            {
                while (s[i] >= '0' && s[i] <= '9')
                {
                    get = get * 10 + s[i++] - '0';
                    num.push(get);
                }
                ++k;
            }
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                re += s[i];
                while (k > 0)
                {
                    start.push(loc);
                    --k;
                }
                ++loc;
            }
            if (s[i] == ']')
            {
                int st = start.top();
                start.pop();
                int len = loc - st;
                int number = num.top();
                num.pop();
                string tmp = re.substr(st, len);
                while (--number)
                {
                    re += tmp;
                    ++loc;
                }
            }
        }
        return re;
    }
};

int main()
{
    Solution().decodeString("3[a10[bc]]");
    return 0;
}