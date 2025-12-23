#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

#include<vector>

using namespace std;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> num(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> num[i][j];
        }
    }
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + num[i][j] - dp[i - 1][j - 1];
        }
    }
    for (auto& e : dp)
    {
        for (auto& k : e)
        {
            cout << k << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < q; ++i)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        cout << dp[y1][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1][x2] << endl;
    }
    return 0;
}