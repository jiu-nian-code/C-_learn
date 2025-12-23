#define _CRT_SECURE_NO_WARNINGS 1

#include"My_String.h"

//void jiunian::string::Expansion()
//{
//	char* ptr = (char*)malloc(2 * (_capacity + 1) * sizeof(char));
//	if (ptr == nullptr)
//	{
//		perror("Expansion:malloc:");
//		return;
//	}
//	memset(ptr, 0, 2 * (_capacity + 1) * sizeof(char));
//	memcpy(ptr, _str, sizeof(char) * _size);
//	free(_str);
//	_str = ptr;
//	_capacity = _capacity * 2 + 1;
//}
	
//jiunian::string::string(const char* str)
//{
//	char* ptr = (char*)malloc((strlen(str) + 1) * sizeof(char));
//	if (ptr == nullptr)
//	{
//		perror("string:malloc:");
//		return;
//	}
//	_str = ptr;
//	for (int i = 0; i < strlen(_str) + 1; ++i)
//	{
//		_str[i] = str[i];
//	}
//	_size = strlen(_str);
//	_capacity = strlen(_str);
//}

jiunian::string::string(const char* str = "")
{
	_size = strlen(_str);
	_capacity = strlen(_str);
	_str = new char[_capacity + 1];
	memcpy(_str, str, _size + 1);
}

jiunian::string::string(const string& s):
	_size(s._size),
	_capacity(s._capacity)
{
	_str = new char[s._capacity + 1];
	memcpy(_str, s._str, (s._size + 1) * sizeof(char));
}

//jiunian::string& jiunian::string::operator=(const string& s)
//{
//	string ex(s);
//	std::swap(ex._str, _str);
//	std::swap(ex._size, _size);
//	std::swap(ex._capacity, _capacity);
//	return *this;
//}

jiunian::string& jiunian::string::operator=(string s)
{
	if(this != &s)
	{
		swap(s);
	}
	return *this;
}

jiunian::string::~string()
{
	//std::cout << "~string";
	delete[] _str;
	_str = nullptr;
	_size = 0;
	_capacity = 0;
}

jiunian::string::iterator jiunian::string::begin()
{
	return _str;
}

jiunian::string::iterator jiunian::string::end()
{
	return _str + _size;
}

void jiunian::string::push_back(char c)
{
	if (_size == _capacity)
		reserve(_capacity == 0 ? 4 : _capacity * 2);
	_str[_size] = c;
	++_size;
	_str[_size] = '\0';
}

void jiunian::string::append(const char* str)
{
	size_t len = strlen(str);
	if (_size + len > _capacity)
	{
		reserve(_size + len);
	}
	memcpy(_str + _size, str, len + 1);
	_size += len;
}

jiunian::string& jiunian::string::operator+=(char c)
{
	push_back(c);
	return *this;
}

jiunian::string& jiunian::string::operator+=(const char* str)
{
	append(str);
	return *this;
}

void jiunian::string::clear()
{
	//memset(_str, 0, _size * sizeof(char));
	_str[0] = '\0';
	_size = 0;
}

void jiunian::string::swap(string& s)
{
	std::swap(_str, s._str);
	std::swap(_size, s._size);
	std::swap(_capacity, s._capacity);
}

const char* jiunian::string::c_str()const
{
	return _str;
}

size_t jiunian::string::capacity()const
{
	return _capacity;
}

size_t jiunian::string::size()const
{
	return _size;
}

bool jiunian::string::empty()const
{
	return _size == 0 ? true : false;
}

void jiunian::string::resize(size_t n, char c)
{
	while (n > _capacity)
	{
		reserve(n + 1);
	}
	if (n > _size)
	{
		for (int i = _size; i < n; ++i)
		{
			_str[i] = c;
		}
	}
	else
	{
		for (int i = n; i < _size; ++i)
		{
			_str[i] = '\0';
		}
	}
	_size = n;
}

void jiunian::string::reserve(size_t n)
{
	if (n <= _capacity)
		return;
	while (n > _capacity)
	{
		/*Expansion();*/
		char* tmp = new char[n + 1];
		memcpy(tmp, _str, _size + 1);

		delete[] _str;
		_str = tmp;
		_capacity = n;
	}
}

char& jiunian::string::operator[](size_t index)
{
	assert(index < _size);
	return _str[index];
}

const char& jiunian::string::operator[](size_t index)const
{
	assert(index < _size);
	return _str[index];
}

jiunian::string jiunian::string::substr(size_t pos = 0, size_t len = npos)
{
	assert(pos < _size);

	size_t n = len;
	if (len == npos || pos + len > _size)
	{
		n = _size - pos;
	}

	string tmp;
	tmp.reserve(n);
	for (size_t i = pos; i < pos + n; i++)
	{
		tmp += _str[i];
	}

	return tmp;
}


bool jiunian::string::operator<(const string& s)
{
	for (int i = 0; i < _size > s._size ? s._size : _size; ++i)//memcmp
	{
		if (_str[i] < s._str[i])
		{
			return true;
		}
		if (_str[i] > s._str[i])
		{
			return false;
		}
	}
	return _size < s._size ? true : false;
}

bool jiunian::string::operator==(const string& s)
{
	if (_size != s._size)
		return false;
	for (int i = 0; i < _size; ++i)
	{
		if (_str[i] != s._str[i])
			return false;
	}
	return true;
}

bool jiunian::string::operator<=(const string& s)
{
	return *this < s || *this == s;
}

bool jiunian::string::operator>(const string& s)
{
	return !(*this <= s);
}

bool jiunian::string::operator>=(const string& s)
{
	return !(*this < s);
}

bool jiunian::string::operator!=(const string& s)
{
	return !(*this == s);
}

size_t jiunian::string::find(char c, size_t pos = 0) const
{
	assert(pos < _size);

	while (pos != _size)
	{
		if (_str[pos++] == c)
		{
			return --pos;
		}
	}
	return npos;
}

size_t jiunian::string::find(const char* s, size_t pos = 0) const
{
	assert(strlen(s) != 0);
	while (pos <= _size - strlen(s))//strstr
	{
		if (_str[pos] == *s && _size - pos > strlen(s))
		{
			int size = strlen(s);
			size_t Pos = pos;
			size_t Old_Pos = pos;
			int record = 0;
			for(int i = 0; i < size; ++i)
			{
				if (_str[Pos] == *s && record != 0 &&pos != 1)
				{
					pos = Pos - 1;
					record = 1;
				}
				if (_str[Pos++] != s[i])
				{
					if (record == 0)
					{
						pos = Pos - 1 - 1;
					}
					record = -1;
					break;
				}
			}
			if (record != -1)
			{
				return Old_Pos;
			}
		}
		++pos;
	}
	return pos;
}

//jiunian::string& jiunian::string::insert(size_t pos, char c)
//{
//	if (_size + 1 > _capacity)
//		Expansion();
//	memmove(_str + pos + 1, _str + pos, _size * sizeof(char));
//	_str[pos] = c;
//	++_size;
//	return *this;
//}

jiunian::string& jiunian::string::insert(size_t pos, size_t n, char c)
{
	assert(pos <= _size);
	if (_size + n > _capacity)
		reserve(_size + n);
	//memmove(_str + pos + n, _str + pos, _size * sizeof(char));
	size_t end = _size;
	if (end >= pos && end != npos)
	{
		_str[end + n] = _str[end];
		--end;
	}
	//_str[pos] = c;

	for (int i = pos; i < pos + n; ++i)
	{
		_str[i] = c;
	}

	_size += n;
	return *this;
}

//jiunian::string& jiunian::string::insert(size_t pos, const char* str)
//{
//	if (_size + strlen(str) > _capacity)
//		Expansion();
//	memmove(_str + pos + strlen(str), _str + pos, _size * sizeof(char));
//	memcpy(_str + pos, str, strlen(str) * sizeof(char));
//	_size += strlen(str);
//	return *this;
//}

jiunian::string& jiunian::string::insert(size_t pos, const char* str)
{
	assert(pos <= _size);
	size_t len = strlen(str);
	if (_size + len > _capacity)
		reserve(_size + len);
	//memmove(_str + pos + n, _str + pos, _size * sizeof(char));
	size_t end = _size;
	if (end >= pos && end != npos)
	{
		_str[end + len] = _str[end];
		--end;
	}
	//_str[pos] = c;

	for (int i = pos; i < pos + len; ++i)
	{
		_str[i] = str[i - pos];
	}

	_size += len;
	return *this;
}

//jiunian::string& jiunian::string::erase(size_t pos, size_t len)
//{
//	assert(pos <= _size);
//	memcpy(_str + pos, _str + pos + len, (_size - pos - len) * sizeof(char));
//	if (len > _size - pos - len)
//	{
//		memset(_str + _size - len, 0, 2 * len - (_size - pos));
//	}
//	_size -= len;
//	return *this;
//}

jiunian::string& jiunian::string::erase(size_t pos, size_t len)
{
	assert(pos <= _size);
	if (len == npos || pos + len >= _size)
	{
		//_str[pos] = '\0';
		_size = pos;

		_str[_size] = '\0';
	}
	else
	{
		size_t end = pos + len;
		while (end <= _size)
		{
			_str[pos++] = _str[end++];
		}
		_size -= len;
	}
}

std::ostream& jiunian::operator<<(std::ostream& _cout, const jiunian::string& s)
{
	_cout << s.c_str();
	return _cout;
}

std::istream& jiunian::operator>>(std::istream& _cin, jiunian::string& s)
{
	s.clear();
	char Get = 0; 
	_cin.get(Get);
	while (Get != '\n')
	{
		s.push_back(Get);
		_cin.get(Get);
	}
	return _cin;
}

std::istream& jiunian::operator>>(std::istream& in, jiunian::string& s)
{
	s.clear();

	char ch = in.get();
	// 处理前缓冲区前面的空格或者换行
	while (ch == ' ' || ch == '\n')
	{
		ch = in.get();
	}

	//in >> ch;
	char buff[128];
	int i = 0;

	while (ch != ' ' && ch != '\n')
	{
		buff[i++] = ch;
		if (i == 127)
		{
			buff[i] = '\0';
			s += buff;
			i = 0;
		}

		//in >> ch;
		ch = in.get();
	}

	if (i != 0)
	{
		buff[i] = '\0';
		s += buff;
	}

	return in;
}