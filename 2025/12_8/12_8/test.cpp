#include<iostream>

#include<vector>

int arr[26] = { 0 };

int main()
{
    int n;
    std::cin >> n;
    int max_num = 0;
    char cur_char;
    for (int i = 0; i < n; ++i)
    {
        char a;
        std::cin >> a;
        arr[a - 'a']++;
        if (arr[a - 'a'] > max_num)
        {
            max_num = arr[a - 'a'];
            cur_char = a;
        }
    }
    if (max_num > (n + 1) / 2) { std::cout << "no" << std::endl; return 0; }
    std::vector<char> num(n);
    for (int i = 0; i < n; i += 2)
    {
        //         std::cout << cur_char << std::endl;
        //         std::cout << num[cur_char - 'a'] << std::endl;
        arr[cur_char - 'a']--;
        num[i] = cur_char;
        while (arr[cur_char - 'a'] == 0)
        {
            if (cur_char == 'z') cur_char = 'a';
            else cur_char++;
        }
    }
    for (int i = 1; i < n; i += 2)
    {
        arr[cur_char - 'a']--;
        num[i] = cur_char;
        char start_char = cur_char;
        while (arr[cur_char - 'a'] == 0)
        {
            if (cur_char == 'z') cur_char = 'a';
            else cur_char++;
            if (start_char == cur_char) break;
        }
    }
    std::cout << "yes" << std::endl;
    for (auto& e : num)
        std::cout << e;
    std::cout << std::endl;
    return 0;
}