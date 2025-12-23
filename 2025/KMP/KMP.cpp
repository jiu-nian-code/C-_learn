#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include<assert.h>

#include<vector>

int kmp(char* str, char* sub, size_t pos)
{
	assert(str != nullptr && sub != nullptr);
	size_t Len_Of_Str = strlen(str);
	size_t Len_Of_Sub = strlen(sub);
	assert(pos < Len_Of_Str);
	assert(Len_Of_Str >= Len_Of_Sub);
	std::vector<int> next;

	for (int i = 0; i < Len_Of_Sub; ++i)//next数组创建
	{
		if (i == 0 || i == 1)
		{
			next.push_back(i == 0 ? -1 : 0);
		}
		else if (sub[next[i - 1]] == sub[i - 1])
		{
			next.push_back(next[i - 1] + 1);
		}
		else
		{
			int comp = next[i - 1];
			while (comp != -1 && sub[comp] != sub[i - 1])
			{
				comp = next[comp];
			}
			next.push_back(comp + 1);
		}
	}

	//for (auto& e : next)
	//{
	//	std::cout << e << " ";
	//}

	int i = pos;
	int j = 0;
	while (i < Len_Of_Str - Len_Of_Sub + 1)//匹配
	{
		while (str[i] == sub[j])
		{
			++i;
			++j;
			if (j == Len_Of_Sub)
				return i - j;
		}
		if (j != 0)
		{
			j = next[j];
		}
		else
		{
			++i;
		}
	}
	return -1;
}

int main()
{
	char str[] = "bbcabcdabc";
	char sub[] = "abcd";
	std::cout << kmp(str, sub, 0) << std::endl;
	return 0;
}