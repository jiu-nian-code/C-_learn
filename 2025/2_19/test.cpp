#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include<vector>

#include<string>

using namespace std;

//class Solution
//{
//public:
//    int firstUniqChar(string s)
//    {
//        int record = 0;
//        int n = 0;
//        for (string::iterator it1 = s.begin(); it1 != s.end(); ++it1)
//        {
//            for (string::iterator it2 = s.begin(); it2 != s.end(); ++it2)
//            {
//                if (*it1 == *it2)
//                    record++;
//                if (record == 2)
//                    break;
//            }
//            if (record != 2)
//            {
//                return n;
//            }
//            record = 0;
//            ++n;
//        }
//        return -1;
//    }
//};

//int main()
//{
//    cout << Solution().firstUniqChar("aabb");
//	return 0;
//}

//int main(int argc, char* argv[])
//{
//
//    string a = "hello world";
//
//    string b = a;
//
//    if (a.c_str() == b.c_str())
//
//    {
//
//        cout << "true" << endl;
//
//    }
//
//    else cout << "false" << endl;
//
//    string c = b;
//
//    c = "";
//
//    if (a.c_str() == b.c_str())
//
//    {
//
//        cout << "true" << endl;
//
//    }
//
//    else cout << "false" << endl;
//
//    a = "";
//
//    if (a.c_str() == b.c_str())
//
//    {
//
//        cout << "true" << endl;
//
//    }
//
//    else cout << "false" << endl;
//
//    return 0;
//
//}

//int main(int argc, char* argv[])
//
//{
//
//    string strText = "How are you? ";
//
//    string strSeparator = " ";
//
//    string strResult;
//
//    int size_pos = 0;
//
//    int size_prev_pos = 0;
//
//    while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)
//
//    {
//
//        strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//
//        cout << strResult << " ";
//
//        size_prev_pos = ++size_pos;
//
//    }
//
//    if (size_prev_pos != strText.size())
//
//    {
//
//        strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//
//        cout << strResult << " ";
//
//    }
//
//    cout << endl;
//
//    return 0;
//
//}

//class Solution
//{
//public:
//    void add(string::iterator& a, const string& s)
//    {
//        while ((*a < 48 || (*a > 57 && *a < 65) || (*a > 90 && *a < 97) || *a > 122)
//            && a != s.end())
//        {
//            ++a;
//        }
//    }
//    void add(string::reverse_iterator& a, const string& s)
//    {
//        while ((*a < 48 || (*a > 57 && *a < 65) || (*a > 90 && *a < 97) || *a > 122)
//            && a != s.rend())
//        {
//            ++a;
//        }
//    }
//    template<class T>
//    void tran(T& a)
//    {
//        if (*a >= 65 && *a <= 90)
//        {
//            *a += 32;
//        }
//    }
//    bool isPalindrome(string s)
//    {
//        string::iterator it = s.begin();
//        string::reverse_iterator rit = s.rbegin();
//        add(it, s);
//        if (it == s.end())
//            return true;
//        //if (it == (rit.base() - 1))
//        //    break;
//        add(rit, s);
//        tran(it);
//        tran(rit);
//        if (*it != *rit)
//        {
//            return false;
//        }
//        while (it != s.end() && rit != s.rend())
//        {
//            add(++it, s);
//            //if (it == s.end())
//            //    return true;
//            if (it == (rit.base() - 1) || it == ((rit + 1).base() - 1))
//                break;
//            add(++rit, s);
//            tran(it);
//            tran(rit);
//            if (*it != *rit)
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//};

//int main()
//{
//    cout << Solution().isPalindrome("A man, a plan, a canal: Panama");
//    return 0;
//}

//class Solution
//{
//public:
//    void Reverse(string::iterator It, string::iterator Prev_It, int size)
//    {
//        for (int i = 0; i < size; ++i)
//        {
//            char ex = *It;
//            *It = *Prev_It;
//            *Prev_It = ex;
//            --It;
//            ++Prev_It;
//        }
//    }
//    string::iterator& add(string::iterator& It, int& Num, string& s)
//    {
//        while (It != s.end() && *It != ' ')
//        {
//            ++Num;
//            ++It;
//        }
//        return It;
//    }
//    string reverseWords(string s)
//    {
//        string::iterator it = s.begin();
//        string::iterator prev_it = it;
//        int num = 0;
//        while (add(it, num, s) != s.end())
//        {
//            Reverse(it - 1, prev_it, num / 2);
//            num = 0;
//            ++it;
//            prev_it = it;
//        }
//        Reverse(it - 1, prev_it, num / 2);
//        return s;
//    }
//};
//
//int main()
//{
//    //Solution().reverseStr("abcdefg", 2);
//    cout << Solution().reverseWords("Let's take LeetCode contest");
//    return 0;
//}

class Solution
{
public:
    template<class T>
    int conversion(T a)
    {
        return *a - 48;
    }
    void Add(string& s1, string& s2)
    {
        auto s1_it = s1.rbegin();
        auto s2_it = s2.rbegin();
        string ex("0");
        int num = s1.size() > s2.size() ? s2.size() : s1.size();
        int prev = 0;
        while (num--)
        {
            int sum = *(s1_it++) + *(s2_it++) - '0' * 2 + prev;
            ex.insert(0, 1, sum % 10 + 48);
            prev = sum / 10;
        }
        if (s1.size() > s2.size())
        {
            while (s1_it != s1.rend())
            {
                int sum = *(s1_it++) - '0' + prev;
                ex.insert(0, 1, sum % 10 + 48);
                prev = sum / 10;
            }
        }
        while (s2_it != s2.rend())
        {
            int sum = *(s2_it++) - '0' + prev;
            ex.insert(0, 1, sum % 10 + 48);
            prev = sum / 10;
        }
        while (prev != 0)
        {
            ex.insert(0, 1, prev % 10 + 48);
            prev /= 10;
        }
        ex.pop_back();
        s1.swap(ex);
    }
    string multiply(string num1, string num2)
    {
        int size_of_num1 = num1.size();
        int size_of_num2 = num2.size();
        auto Str_Arr = new string[size_of_num1];
        for (int i = 0; i < size_of_num1; ++i)
        {
            Str_Arr[i] += '0';
        }
        auto rit_1 = num1.rbegin();
        auto rit_2 = num2.rbegin();
        for (int i = 0; i < size_of_num1; ++i)
        {
            int prev_pro = 0;
            for (int j = 0; j < size_of_num2; ++j)
            {
                int product = conversion(rit_1) * conversion(rit_2++) + prev_pro;
                Str_Arr[i].insert(0, 1, product % 10 + '0');
                prev_pro = product / 10;
            }
            while (prev_pro != 0)
            {
                Str_Arr[i].insert(0, 1, prev_pro % 10 + 48);
                prev_pro /= 10;
            }
            rit_2 = num2.rbegin();
            for (int k = 0; k < i; ++k)
            {
                Str_Arr[i] += '0';
            }
            ++rit_1;
        }
        for (int i = 0; i < size_of_num1; ++i)
        {
            Str_Arr[i].pop_back();
        }
        string ret(Str_Arr[0]);
        for (int i = 1; i < size_of_num1; ++i)
        {
            Add(ret, Str_Arr[i]);
        }
        while (ret[0] == '0' && ret.size() != 1)
        {
            ret.erase(0, 1);
        }
        return ret;
    }
};

int main()
{
    Solution().multiply("9133", "0");
    return 0;
}