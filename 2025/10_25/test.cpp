#include<iostream>

template<class T = int>
class sqlist
{
	void expansion()
	{
		T* tmp = new T[_cap * 2];
		if (!tmp)
		{
			perror("new");
			return;
		}
		for (int i = 0; i < _cap; ++i)
			tmp[i] = _arr[i];

		delete[] _arr;
		_arr = tmp;
		_cap *= 2;
	}

	static const int init_cap = 10;
public:
	sqlist() :
		_arr(nullptr),
		_size(0),
		_cap(0)
	{
		_arr = new T[init_cap];
		if (!_arr)
		{
			perror("new");
			return;
		}
		_cap = init_cap;
	}

	void push_back(const T& x)
	{
		if (_size == _cap) expansion();
		insert(_size, x);
	}

	void insert(int pos, const T& x)
	{
		if (pos > _size)
		{
			std::cout << "pos error" << std::endl;
			return;
		}
		if (_size == _cap) expansion();
		for (int i = _size - 1; i >= pos; --i)
			_arr[i + 1] = _arr[i];

		_arr[pos] = x;
		++_size;
	}

	void erase(int pos)
	{
		if (empty())
		{
			std::cout << "sqlist is empty, erase error" << std::endl;
			return;
		}
		for (int i = pos + 1; i < _size; ++i)
			_arr[i - 1] = _arr[i];
		--_size;
	}

	int size()
	{
		return _size;
	}

	int capcity()
	{
		return _cap;
	}

	void PRINT()
	{
		for (int i = 0; i < _size; ++i)
			std::cout << _arr[i] << std::endl;
	}

	bool empty()
	{
		return _size == 0 ? true : false;
	}

	T& operator[](int pos)
	{
		return _arr[pos];
	}

	int find(T x)
	{
		for (int i = 0; i < _size; ++i)
			if (_arr[i] == x) return i;
	}

	~sqlist()
	{
		delete[] _arr;
	}
private:
	T* _arr;
	int _size;
	int _cap;
};

int main()
{
	//sqlist<> a;
	sqlist<char> sq;
	sq.push_back('a');
	sq.push_back('b');
	sq.push_back('c');
	sq.push_back('d');
	sq.push_back('e');

	sq.PRINT();

	std::cout << sq.size() << std::endl;
	// std::cout << sq.capcity() << std::endl;

	std::cout << sq.empty() << std::endl;

	std::cout << sq[2] << std::endl;

	std::cout << sq.find('a') << std::endl;

	sq.insert(3, 'f');

	sq.PRINT();

	sq.erase(2);

	sq.PRINT();

	return 0;
}