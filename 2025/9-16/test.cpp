#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

class father
{
public:
	virtual void money()
	{
		cout << 1000000 << endl;
	}
};

class son : public father
{
public:
	virtual void money()
	{
		cout << 1000 << endl;
	}
};

class sonofson : public son
{
public:
	virtual void money()
	{
		cout << 1000 << endl;
	}
};

int main()
{
	father fa;
	son so;
	sonofson sos;
	father* x = &fa;
	x->money();//1000000
	x = &so;
	x->money();//1000
	x = &sos;
	x->money();
	return 0;
}