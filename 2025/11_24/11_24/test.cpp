#include <iostream>
using namespace std;

int main()
{
    std::string str;
    std::cin >> str;
    int _max = 0;
    int cur_num = 0;
    int left = 0;
    int maxleft = 0;
    int maxright = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        auto& e = str[i];
        if (e >= '0' && e <= '9')
        {
            if (cur_num == 0) left = i;
            ++cur_num;
        }
        else
        {
            // std::cout << cur_num << std::endl;
            if (cur_num > _max)
            {
                maxleft = left;
                maxright = i - 1;
                _max = cur_num;
            }
            cur_num = 0;
        }
    }

    if (cur_num > _max)
    {
        maxleft = left;
        maxright = str.size() - 1;
        _max = cur_num;
    }

    for (int i = maxleft; i <= maxright; ++i)
    {
        std::cout << str[i];
    }
    std::cout << std::endl;
    return 0;
}

class Solution {
public:
    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };
    int max_x;
    int max_y;

    void dfs(vector<vector<char> >& grid, int x, int y)
    {
        grid[x][y] = '0';
        for (int i = 0; i < 4; ++i)
        {
            int a = x + dx[i];
            int b = y + dy[i];
            if (a >= 0 && a < max_x && b >= 0 && b <= max_y && grid[a][b] == '1')
            {
                dfs(grid, a, b);
            }
        }
    }

    int solve(vector<vector<char> >& grid)
    {
        max_x = grid.size();
        max_y = grid[0].size();
        int ret = 0;
        for (int i = 0; i < max_x; ++i)
        {
            for (int j = 0; j < max_y; ++j)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    ++ret;
                }
            }
        }
        return ret;
    }
};

#include<iostream>

int arr[6] = { 0 };

bool check(int a, int b, int c)
{
    return (a + b > c) && (a + c > b) && (b + c > a);
}

void task()
{
    int i = 0;
    for (int j = i + 1; j < 6; ++j)
    {
        for (int l = j + 1; l < 6; ++l)
        {
            bool ret1 = check(arr[i], arr[j], arr[l]);
            int less[3] = { 0 };
            int a = 0;
            for (int cur = 1; cur < 6; ++cur)
            {
                if (cur != j && cur != l) less[a++] = cur;
            }
            bool ret2 = check(arr[less[0]], arr[less[1]], arr[less[2]]);
            if (ret1 && ret2) { std::cout << "Yes" << std::endl; return; }
        }
    }
    std::cout << "No" << std::endl;
}

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        for (int i = 0; i < 6; ++i) std::cin >> arr[i];
        task();
    }
    return 0;
}