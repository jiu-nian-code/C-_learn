#include<iostream>
#include<fstream>
#include<print>
#include<string>
#include<vector>
#include<queue>

using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int solution(vector<string> arg1, string arg2)
{
    if (arg2.size() == 0) return 0;
    std::queue<std::pair<int, int>> qu;
    for (int i = 0; i < arg1.size(); ++i)
    {
        for (int j = 0; j < arg1[0].size(); ++j)
        {
            if (arg1[i][j] == arg2[0])
            {
                std::cout << i << " " << j << std::endl;
                qu.push(std::make_pair(i, j));
            }
        }
    }
    if (qu.size() == 0) return -1;
    int cur = 1;
    int step = 1;
    while (!qu.empty() && cur < arg2.size())
    {
        size_t sz = qu.size();
        std::queue<std::pair<int, int>> swp;
        while (sz--)
        {
            int x = qu.front().first;
            int y = qu.front().second;
            for (int i = 0; i < 4; ++i)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if (newx >= 0 && newx < arg1.size() && newy >= 0 && newy < arg1[0].size())
                {
                    if (arg1[newx][newy] == arg2[cur])
                    {
                        std::cout << newx << " " << newy << std::endl;
                        swp.push(std::make_pair(newx, newy));
                    }
                    else qu.push(std::make_pair(newx, newy));
                }
            }
            qu.pop();
        }
        if (!swp.empty()) ++cur, qu.swap(swp);
        if (!qu.empty()) ++step;
    }
    if (cur == arg2.size()) return step;
    return -1;
}

int main()
{

	return 0;
}