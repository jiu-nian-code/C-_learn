#define _CRT_SECURE_NO_WARNINGS 1

#include"My_Queue.h"

int main()
{
	jiunian::queue<int> qu;
	qu.push(1);
	qu.push(2);
	qu.push(3);
	qu.push(4);
	qu.push(5);

	//cout << qu.empty() << endl;

	//cout << qu.size() << endl;

	//cout << qu.front() << " " << qu.back() << endl;

	//qu.pop();
	//qu.pop();
	//qu.pop();
	////qu.pop();
	////qu.pop();

	//cout << qu.front() << " " << qu.back() << endl;

	//cout << qu.empty() << endl;

	//cout << qu.size() << endl;

	jiunian::queue<int> Qu(qu);

	//Qu = qu;

	cout << Qu.front() << " ";
	cout << Qu.back();
	return 0;
}