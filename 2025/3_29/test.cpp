#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include<vector>

using namespace std;

class Solution
{
    bool hash[6][6] = { 0 };
public:
    bool _exist(vector<vector<char>>& board, string word, int pos, int x, int y)
    {
        if (pos == word.size()) return true;
        if (hash[x][y] == 1 || x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[pos]) return false;
        hash[x][y] = 1;
        if (_exist(board, word, pos + 1, x + 1, y)) return true;
        if (_exist(board, word, pos + 1, x, y + 1)) return true;
        if (_exist(board, word, pos + 1, x - 1, y)) return true;
        if (_exist(board, word, pos + 1, x, y - 1)) return true;
        hash[x][y] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] != word[0]) continue;
                hash[i][j] = 1;
                if (_exist(board, word, 1, i, j)) return true;
                hash[i][j] = 0;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<char>>tmp{ {A, B, C, E}, {S, F, C, S}, {A, D, E ,E} };
    Solution().exist(tmp);
    return 0;
}