#define _CRT_SECURE_NO_WARNINGS 1

#include<vector>

#include<string>

using namespace std;


class Solution
{
    vector<vector<bool>> dia_hash{ 3, vector<bool>(10) };
public:
    bool _isValidSudoku(vector<vector<char>>& board, int pos)
    {
        if (pos == 9) return true;
        bool row_hash[10] = { 0 };
        if (pos % 3 == 0 && pos / 3 > 0) dia_hash.clear();
        for (int i = 0; i < 9; ++i)
        {
            if (board[pos][i] == '.') continue;
            if (row_hash[board[pos][i] - '0'] == 1 || dia_hash[pos % 3][board[pos][i] - '0'] == 1) return false;
            row_hash[board[pos][i] - '0'] = 1;
            dia_hash[pos % 3][board[pos][i] - '0'] == 1;
        }
        return _isValidSudoku(board, pos + 1);
    }

    bool isValidSudoku(vector<vector<char>>& board)
    {
        return _isValidSudoku(board, 0);
    }
};
int main()
{
    vector<vector<int>> tmp{ {1,2,3},{1,2,3 },{1,2,3} };
    tmp[0].clear();
    tmp[1].clear();
    tmp[2].clear();
    tmp.clear();
    return 0;
}