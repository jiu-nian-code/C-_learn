#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include<string>

using namespace std;

//int main()
//{
//	int a, b, n;
//	cin >> n;
//	cin >> a >> b;
//	int min_anwser = a / (b + 1) + 1;;
//	int max_anwser = a / b;
//	for (int i = 0; i < n - 1; ++i)
//	{
//		cin >> a >> b;
//		if (min_anwser < (a / (b + 1)) + 1)
//			min_anwser = a / (b + 1) + 1;
//		if (max_anwser > a / b)
//			max_anwser = a / b;
//	}
//	cout << min_anwser << " " << max_anwser << endl;
//	return 0;
//}

//int main()
//{
//	cout << "int(3): " << int(3) << endl;
//	return 0;
//}

//int main()
//{
//	std::string();//匿名对象
//	std::string("123");//同样是匿名对象，只要不加名字就是，给不给值初始化都一样
//	std::string str = std::string("123");//匿名对象赋值，这里编译器会优化成直接用"123"给str初始化、
//	const std::string& example = std::string("123");
//	std::string Example = example;//安全操作
//	std::cout << Example << std::endl;//打印结果是123
//	return 0;
//}

//int globalVar = 1;
//static int staticGlobalVar = 1;
//void Test()
//{
//    static int staticVar = 1;
//    int localVar = 1;
//
//    int num1[10] = { 1, 2, 3, 4 };
//    char char2[] = "abcd";
//    const char* pChar3 = "abcd";
//    int* ptr1 = (int*)malloc(sizeof(int) * 4);
//    int* ptr2 = (int*)calloc(4, sizeof(int));
//    int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//    free(ptr1);
//    free(ptr3);
//}
//
//1. 选择题：
//选项 : A.栈  B.堆  C.数据段(静态区)  D.代码段(常量区)
//globalVar在哪里？____   staticGlobalVar在哪里？____
//staticVar在哪里？____   localVar在哪里？____
//num1 在哪里？____
//
//char2在哪里？____ * char2在哪里？___
//pChar3在哪里？____ * pChar3在哪里？____、
//ptr1在哪里？____
//2. 填空题：
//sizeof(num1) = ____;
//sizeof(char2) = ____;
//sizeof(pChar3) = ____;
//sizeof(ptr1) = ____;
//3. sizeof 和 strlen 区别？

//class jiunian
//{
//public:
//	jiunian()
//	{
//		a++;
//		b += a;
//	}
//	static int& GetB()
//	{
//		return b;
//	}
//private:
//	static int a;
//	static int b;
//};
//
//int jiunian::a = 0;
//int jiunian::b = 0;
//
//int main()
//{
//	jiunian* exam = new jiunian[10];
//	std::cout << jiunian::GetB() << std::endl;
//	return 0;
//}

int main()
{
	int* a = new int;//开空间不初始化
	int* b = new int(1);//开空间初始化
	int* c = new int[10];//开10个int类型的空间不初始化
	int* d = new int[10] {};//开10个int类型的空间初始化为0
	int* e = new int[10] {0};//开10个int类型的空间初始化为0
	int* f = new int[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};//开10个int类型的空间初始化为想要的数
	string* g = new string;//开类类型空间不初始化（调用默认构造）
	string* h = new string("Hello World");//开类类型空间初始化（调用构造）
	string* i = new string[10];//开10个类类型数组不初始化（调用10次默认构造）
	string* j = new string[10]{"jiunian"};//开10个类类型数组初始化了第一个（第一个调用构造，其他默认构造）
	delete a;
	delete b;//不是数组直接删
	delete[] c;
	delete[] d;
	delete[] e;
	delete[] f;//是数组delete后面加[]再删
	delete g;
	delete h;//类类型删除会调用析构函数
	delete[] i;
	delete[] j;//调用10次析构函数
	return 0;
}