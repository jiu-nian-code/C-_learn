#define _CRT_SECURE_NO_WARNINGS 1

#include"My_Unordered_Set.h"

#include"My_Unordered_Map.h"

#include"hash.h"

//void test_1()
//{
//	Open_Addressing::Hash<int, int> x;
//
//	//x.insert(57, 1);
//	//x.insert(27, 1);
//	//x.insert(37, 1);
//	//x.insert(100, 1);
//	//x.insert(81, 1);
//	//x.insert(69, 1);
//	//x.insert(77, 1);
//	//x.insert(18, 1);
//	//x.insert(33, 1);
//	//x.insert(10, 1);
//	//x.insert(117, 1);
//	//x.erase(117);
//	//x.insert(200, 1);
//
//	//cout << x.find(57) << endl;
//	//cout << x.find(27) << endl;
//	//cout << x.find(37) << endl;
//	//cout << x.find(100) << endl;
//	//cout << x.find(81) << endl;
//	//cout << x.find(69) << endl;
//	//cout << x.find(77) << endl;
//	//cout << x.find(18) << endl;
//	//cout << x.find(33) << endl;
//	//cout << x.find(10) << endl;
//	//cout << x.find(200) << endl;
//
//	cout << x.insert(1, 1);
//	cout << x.erase(1);
//	cout << x.insert(2, 1);
//	cout << x.erase(2);
//	cout << x.insert(3, 1);
//	cout << x.erase(3);
//	cout << x.insert(4, 1);
//	cout << x.erase(4);
//	cout << x.insert(5, 1);
//	cout << x.erase(5);
//	cout << x.insert(6, 1);
//	cout << x.erase(6);
//	cout << x.insert(7, 1);
//	cout << x.erase(7);
//	cout << x.insert(8, 1);
//	cout << x.erase(8);
//	cout << x.insert(9, 1);
//	cout << x.erase(9);
//	cout << x.insert(10, 1);
//	cout << x.erase(10);
//
//	cout << x.erase(10);
//
//	//cout << x.find(1);
//
//	//cout << x.size();
//}
//
//void test_2()
//{
//	//Hash_bucket::Hash<int, int> x;
//
//	//cout << x.insert(57, 1);
//	//cout << x.insert(27, 1);
//	//cout << x.insert(37, 1);
//	//cout << x.insert(100, 1);
//	//cout << x.insert(81, 1);
//	//cout << x.insert(69, 1);
//	//cout << x.insert(77, 1);
//	//cout << x.insert(18, 1);
//	//cout << x.insert(33, 1);
//	//cout << x.insert(10, 1);
//	//cout << x.insert(117, 1);
//	//cout << x.erase(117);
//	//cout << x.insert(200, 1);
//	//cout << x.erase(200);
//	//cout << x.erase(200);
//	//cout << x.erase(100);
//
//	//cout << x.find(57) << endl;
//	//cout << x.find(27) << endl;
//	//cout << x.find(37) << endl;
//	//cout << x.find(100) << endl;
//	//cout << x.find(81) << endl;
//	//cout << x.find(69) << endl;
//	//cout << x.find(77) << endl;
//	//cout << x.find(18) << endl;
//	//cout << x.find(33) << endl;
//	//cout << x.find(10) << endl;
//	//cout << x.find(117) << endl;
//	//cout << x.find(200) << endl;
//}
//
//void test_3()
//{
//	My_Unordered_Set<int> x;
//	cout << x.insert(100) << endl;
//	cout << x.insert(21) << endl;
//	cout << x.insert(37) << endl;
//	cout << x.insert(48) << endl;
//	cout << x.insert(51) << endl;
//	cout << x.insert(26) << endl;
//	cout << x.insert(46) << endl;
//	cout << x.insert(69) << endl;
//	cout << x.insert(326) << endl;
//	cout << x.insert(54) << endl;
//	cout << x.insert(13) << endl;
//	cout << x.insert(99) << endl;
//	cout << x.insert(1000) << endl;
//	cout << x.insert(11) << endl;
//	cout << x.erase(11) << endl;
//	cout << x.insert(622) << endl << endl;
//
//	cout << x.find(100) << endl;
//	cout << x.find(21) << endl;
//	cout << x.find(37) << endl;
//	cout << x.find(48) << endl;
//	cout << x.find(51) << endl;
//	cout << x.find(26) << endl;
//	cout << x.find(46) << endl;
//	cout << x.find(69) << endl;
//	cout << x.find(326) << endl;
//	cout << x.find(54) << endl;
//	cout << x.find(13) << endl;
//	cout << x.find(99) << endl;
//	cout << x.find(1000) << endl;
//	cout << x.find(11) << endl;
//	cout << x.find(622) << endl;
//}
//
//void test_4()
//{
//	My_Unordered_Set<string> x;
//	x.insert("abcd");
//	x.insert("bacd");
//	x.insert("abdc");
//	x.insert("acbd");
//	x.insert("cabjc");
//	x.insert("gsfdjg");
//	x.insert("afns");
//	x.insert("vnskjdn");
//	x.insert("vsdrjjbjg");
//	x.insert("casbv");
//	x.insert("tewb");
//
//	cout << x.find("abcd");
//	cout << x.find("bacd");
//	cout << x.find("abdc");
//	cout << x.find("acbd");
//	cout << x.find("cabjc");
//	cout << x.find("gsfdjg");
//	cout << x.find("afns");
//	cout << x.find("vnskjdn");
//	cout << x.find("vsdrjjbjg");
//	cout << x.find("casbv");
//	cout << x.find("tewb");
//}
//
//void test_5()
//{
//	My_Unordered_Map<int, int> x;
//	x.insert(make_pair(51, 1));
//	x.insert(make_pair(23, 1));
//	x.insert(make_pair(37, 1));
//	x.insert(make_pair(114, 1));
//	x.insert(make_pair(514, 1));
//	x.insert(make_pair(63, 1));
//	x.insert(make_pair(79, 1));
//	x.insert(make_pair(38, 1));
//	x.insert(make_pair(99, 1));
//	x.insert(make_pair(100, 1));
//	x.insert(make_pair(101, 1));
//	x.insert(make_pair(120, 1));
//	x.erase(120);
//
//	cout << x.find(51);
//	cout << x.find(23);
//	cout << x.find(37);
//	cout << x.find(114);
//	cout << x.find(514);
//	cout << x.find(63);
//	cout << x.find(79);
//	cout << x.find(38);
//	cout << x.find(99);
//	cout << x.find(100);
//	cout << x.find(101);
//	cout << x.find(120);
//}

//struct Set_Fetch_Ruler
//{
//	const int& operator()(const int& a)
//	{
//		return a;
//	}
//};

void test_6()
{
	My_Unordered_Map<int, int> x;
	x[1] = 1;
	x[2] = 1;
	x[3] = 1;
	x[4] = 1;
	x[5] = 1;
	x[6] = 1;

	for (auto& e : x)
	{
		e.second = 2;
		cout << e.first << endl;
	}
}

void test_7()
{
	My_Unordered_Set<int> x;
	x.insert(1);
	x.insert(2);
	x.insert(3);
	x.insert(4);
	x.insert(5);

	auto it = x.begin();
	//*x = 1;
}

int main()
{
	test_7();
	return 0;
}