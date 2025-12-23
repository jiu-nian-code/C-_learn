//#include <iostream>
//
//#include<vector>
//using namespace std;
//
//int main()
//{
//    int n;
//    std::cin >> n;
//    if (n == 0) { std::cout << 0 << std::endl; exit(0); }
//    std::vector<int> arr(n);
//    for (int i = 0; i < n; ++i)
//    {
//        std::cin >> arr[i];
//    }
//
//    int start = arr[0];
//    int re = 0;
//    for (int i = 1; i < n; ++i)
//    {
//        if (arr[i] < arr[i - 1])
//        {
//            // std::cout << arr[i] << std::endl;
//            re = max(arr[i - 1] - start, re);
//            if (arr[i] < start) start = arr[i];
//        }
//    }
//    std::cout << re << std::endl;
//    return 0;
//}
//
//#include <iostream>
//using namespace std;
//
//int dx[2] = { 1, 0 };
//int dy[2] = { 0, 1 };
//
//bool arr[40][40] = { 0 };
//int num = 0;
//int n;
//int m;
//
//void dfs(int x, int y)
//{
//    if (x == n && y == m) { ++num; return; }
//    if (x > n || y > m) return;
//    // arr[n][m] = true;
//    for (int i = 0; i < 2; ++i)
//    {
//        int a = x + dx[i];
//        int b = y + dy[i];
//        if (a >= 0 && b >= 0 && arr[a][b] == false)
//        {
//            dfs(a, b);
//            // arr[a][b] = false;
//        }
//    }
//}
//
//int main()
//{
//    int x, y;
//    std::cin >> n >> m >> x >> y;
//    arr[x][y] = true;
//    for (int i = -2; i <= 2; ++i)
//    {
//        if (i == 0) continue;
//        int j = 3 - abs(i);
//        int a = x + i;
//        int b = y + j;
//        if (a >= 0 && b >= 0) arr[a][b] = true;
//
//        j = 3 - abs(i);
//        // a = x + i;
//        b = y - j;
//        if (a >= 0 && b >= 0) arr[a][b] = true;
//    }
//
//    dfs(0, 0);
//    std::cout << num << std::endl;
//    return 0;
//}
//
//class Solution {
//public:
//    int getLongestPalindrome(string A)
//    {
//        int ret = 0;
//        for (int i = 0; i < A.size(); ++i)
//        {
//            int left = i - 1;
//            int right = i + 1;
//            int length = 1;
//            while (left >= 0 && right < A.size())
//            {
//                if (A[left] == A[right])
//                {
//                    --left;
//                    ++right;
//                    length += 2;
//                }
//            }
//            ret = max(ret, length);
//
//            left = i;
//            right = i + 1;
//            length = 0;
//            while (left >= 0 && right < A.size())
//            {
//                if (A[left] == A[right])
//                {
//                    --left;
//                    ++right;
//                    length += 2;
//                }
//            }
//            ret = max(ret, length);
//        }
//        return ret;
//    }
//};

#include <iostream>

#include<vector>
using namespace std;

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];

    int prevmini = arr[0];
    int sum = 0;
    for (int i = 1; i < arr.size(); ++i)
    {
        if (arr[i] < arr[i - 1])
        {
            sum += (arr[i - 1] - prevmini);
            prevmini = arr[i];
        }
        if (i == arr.size() - 1) sum += (arr[i] - prevmini);
    }
    std::cout << sum << std::endl;
    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    std::string str;
    std::getline(std::cin, str);
    std::string newstr;
    int prev = str.size();
    // std::cout << str << std::endl;
    for (int i = str.size() - 1; i >= 0; --i)
    {
        if (str[i] == ' ')
        {
            // std::cout << i << std::endl;
            // std::cout << prev << std::endl;
            // std::cout << str.substr(i + 1, prev) << 1 << std::endl;
            newstr += str.substr(i + 1, prev - i - 1);
            newstr += ' ';
            prev = i;
        }
    }
    newstr += str.substr(0, prev);
    std::cout << newstr << std::endl;
}

#include <iostream>

#include<unordered_set>
using namespace std;

int main()
{
    std::string str1;
    std::string str2;
    std::getline(std::cin, str1);
    std::getline(std::cin, str2);
    std::unordered_set<char> set;
    for (auto& e : str2)
        set.insert(e);
    std::string ret;
    for (auto& e : str1)
        if (set.count(e) == 0) ret += e;
    std::cout << ret << std::endl;
    return 0;
}

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
    {
        std::unordered_set<ListNode*> set;
        ListNode* cur1 = pHead1;
        ListNode* cur2 = pHead2;
        while (cur1 && cur2)
        {
            if (set.count(cur1) == 0)set.insert(cur1);
            else return cur1;
            if (set.count(cur2) == 0)set.insert(cur2);
            else return cur2;

            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        while (cur1)
        {
            if (set.count(cur1) == 0)set.insert(cur1);
            else return cur1;
            cur1 = cur1->next;
        }
        while (cur2)
        {
            if (set.count(cur2) == 0)set.insert(cur2);
            else return cur2;
            cur2 = cur2->next;
        }
        return nullptr;
    }
};

#include <iostream>

#include<vector>
using namespace std;

int main()
{
    long long n;
    std::cin >> n;
    long long num_s = 0;
    long long num_h = 0;
    long long ret = 0;
    for (int i = 0; i < n; ++i)
    {
        char e;
        std::cin >> e;
        if (e == 's') ++num_s;
        if (e == 'h') num_h = num_h + num_s;
        if (e == 'y') ret += num_h;
    }
    std::cout << ret << std::endl;
    return 0;
}