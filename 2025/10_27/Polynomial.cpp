#include<iostream>

#include<vector>

#include<set>

#include <stdarg.h>

struct Element
{
	Element(int coefficient, int index) :
		_index(index),
		_coefficient(coefficient)
	{
	}

	int _coefficient;
	int _index;
};

struct Compare_Ruler_Of_Element
{
	bool operator()(const Element& a, const Element& b) const
	{
		return a._index > b._index ? true : false;
	}
};

class Polynomial
{
	typedef Polynomial Self;
public:
	Polynomial(int count, ...)
	{
		va_list ap;
		va_start(ap, count);

		for (int i = 0; i < count; ++i)
			_arr.insert(va_arg(ap, Element));
		va_end(ap);
	}

	std::vector<Element> operator+(const Self& y)
	{
		auto it_x = _arr.begin();
		auto it_y = y._arr.begin();
		std::vector<Element> ret;

		while (it_x != _arr.end() && it_y != y._arr.end())
		{
			if (it_x->_index == it_y->_index)
			{
				ret.push_back(Element(it_x->_coefficient + it_y->_coefficient, it_x->_index));
				it_x++;
				it_y++;
			}
			else
			{
				if (it_x->_index > it_y->_index)
				{
					ret.push_back(Element(it_x->_coefficient, it_x->_index));
					it_x++;
				}
				else
				{
					ret.push_back(Element(it_y->_coefficient, it_y->_index));
					it_y++;
				}
			}
		}

		while (it_x != _arr.end())
		{
			ret.push_back(Element(it_x->_index, it_x->_coefficient));
			it_x++;
		}

		while (it_y != y._arr.end())
		{
			ret.push_back(Element(it_y->_index, it_y->_coefficient));
			it_y++;
		}

		return ret;
	}

	void PRINT() // for debug
	{
		for (auto& e : _arr)
		{
			std::cout << e._coefficient << " " << e._index << std::endl;
		}
	}

private:
	std::set<Element, Compare_Ruler_Of_Element> _arr;
};

void print_result(const std::vector<Element>& re)
{
	bool isinloop = false;
	for (auto& e : re)
	{
		if (!isinloop) isinloop = true;
		else std::cout << " + ";

		if (e._index != 0)
		{
			if (e._coefficient > 0)
				std::cout << e._coefficient << "x^" << e._index;
			else
				std::cout << '-' << abs(e._coefficient) << "x^" << e._index;
		}
		else
		{
			if (e._coefficient > 0)
				std::cout << e._coefficient;
			else
				std::cout << '-' << abs(e._coefficient);
		}
	}
	std::cout << std::endl;
}

int main()
{
	Polynomial a(4, Element(5, 1), Element(4, 3), Element(3, 0), Element(-2, 2));
	Polynomial b(4, Element(6, 0), Element(2, 3), Element(3, 2), Element(-1, 1));

	//a.PRINT();
	//b.PRINT();

	std::vector<Element> result = a + b;

	print_result(result);

	return 0;
}