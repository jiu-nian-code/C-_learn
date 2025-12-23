#include<iostream>

#include<vector>

#include<queue>

using namespace std;

class Solution
{
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
public:
    int cutOffTree(vector<vector<int>>& forest)
    {
        int m = forest.size();
        int n = forest[0].size();
        int aim = INT_MIN;
        for (auto& e : forest)
            for (auto& k : e)
                aim = max(aim, k);
        queue<pair<int, int>>qu;
        qu.push(make_pair(-1, 0));
        int ret = -1;
        int Find = 2;
        while (!qu.empty())
        {
            ++ret;
            int size = qu.size();
            bool isfind = false;
            while (size-- && !isfind)
            {
                pair<int, int> t(qu.front());
                qu.pop();
                for (int k = 0; k < 4; ++k)
                {
                    int i = t.first + dx[k];
                    int j = t.second + dy[k];
                    if (i >= 0 && i < m && j >= 0 && j < n && forest[i][j] == Find)
                    {
                        if (Find == aim) return ret;
                        ++Find;
                        queue<pair<int, int>>tmp;
                        tmp.swap(qu);
                        qu.push(make_pair(i, j));
                        forest[i][j] = 1;
                        isfind = true;
                        break;
                    }
                    else if (i >= 0 && i < m && j >= 0 && j < n && forest[i][j] == 1)
                    {
                        qu.push(make_pair(i, j));
                    }
                }
            }
        }
        return -1;
    }
};

int main()
{
    vector<vector<int>> tmp{ {1,2,3},{0,0,0},{7,6,5} };
    Solution().cutOffTree(tmp);
    return 0;
}