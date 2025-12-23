#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

#include<vector>

#include<assert.h>

namespace jiunian
{
    template<class T>
    class vector
    {
    public:
        typedef T* iterator;

        typedef const T* const_iterator;

        iterator begin()
        {
            return _start;
        }

        iterator end()
        {
            return _finish;
        }

        const_iterator begin() const
        {
            return _start;
        }

        const_iterator end() const
        {
            return _finish;
        }

        // construct and destroy
        vector() {}

        //vector(int n, const T& value = T())
        //{
        //    reserve(n);
        //    for (int i = 0; i < n; ++i)
        //    {
        //        _start[i] = value;
        //    }
        //    _finish = _start + n;
        //}

        vector(int n, const T& value = T())
        {
            resize(n, value);
        }

        //template<class InputIterator>
        //vector(InputIterator first, InputIterator last)
        //{
        //    reserve(last - first);
        //    iterator it = begin();
        //    iterator It = first;
        //    while (It != last)
        //    {
        //        *(it++) = *(It++);
        //    }
        //    _finish = _start + (last - first);
        //}

        template<class InputIterator>
        vector(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                push_back(*first);
                ++first;
            }
        }

        //vector(const vector<T>& v)
        //{
        //    //T* ptr = new T[v.capacity()];
        //    reserve(v.capacity());
        //    //memcpy(_start, v._start, v.size() * sizeof(T));
        //    iterator it = begin();
        //    const_iterator cit = v.cbegin();
        //    while (cit != v.cend())
        //    {
        //        *(it++) = *(cit++);
        //    }
        //    _finish = it;
        //}

        //vector(const vector<T>& v)
        //{
        //    _start = new T[v.capacity()];
        //    //memcpy(_start, v._start, sizeof(T)*v.size());
        //    for (size_t i = 0; i < v.size(); i++)
        //    {
        //        _start[i] = v._start[i];
        //    }

        //    _finish = _start + v.size();
        //    _endofstorage = _start + v.capacity();
        //}

        vector(const vector<T>& v)
        {
            //T* ptr = new T[v.capacity()];
            reserve(v.capacity());
            //memcpy(_start, v._start, v.size() * sizeof(T));
            for(auto e : v)
            {
                push_back(e);
            }
        }

        vector<T>& operator= (vector<T> v)
        {
            swap(v);
            return *this;
        }

        ~vector()
        {
            if (_start == nullptr)
                return;
            //std::cout << "~vector" << std::endl;
            delete[] _start;
            _start = nullptr;
            _finish = nullptr;
            _endOfStorage = nullptr;
        }

        // capacity
        size_t size() const
        {
            return _finish - _start;
        }

        size_t capacity() const
        {
            return _endOfStorage - _start;
        }

        void reserve(size_t n)
        {
            if (n <= capacity())
                return;
            size_t Old_Size = size();//坑
            T* ptr = new T[n]{};
            //iterator pos = _start;
            if(_start)
            {
                memcpy(ptr, _start, Old_Size * sizeof(T));
                delete[] _start;
            }
            _start = ptr;
            _finish = ptr + Old_Size;
            _endOfStorage = ptr + n;
        }

        void resize(size_t n, const T& value = T())
        {
            if (n < size())
            {
                _finish = _start + n;
                return;
            }
            reserve(n);

            while (_finish != _start + n)
            {
                *_finish = value;
                ++_finish;
            }
            return;
        }

        ///////////////access///////////////////////////////
        T& operator[](size_t pos)
        {
            assert(pos < size());
            return _start[pos];
        }

        const T& operator[](size_t pos)const
        {
            assert(pos < size());
            return _start[pos];
        }

        ///////////////modify/////////////////////////////
        //void push_back(const T& x)
        //{
        //    if (_finish == _endOfStorage)
        //    {
        //        reserve(capacity() == 0 ? 4 : 2 * capacity());
        //    }
        //    *_finish = x;
        //    ++_finish;
        //}

        void push_back(const T& x)
        {
            insert(end(), x);
        }

        void pop_back()
        {
            iterator pos = end() - 1;
            erase(pos);
        }

        void swap(vector<T>& v)
        {
            std::swap(v._start, _start);
            std::swap(v._finish, _finish);
            std::swap(v._endOfStorage, _endOfStorage);
        }

        iterator insert(iterator pos, const T& x)//迭代器失效
        {
            assert(pos >= _start && pos <= _finish);
            if (_finish == _endOfStorage)
            {
                size_t len = pos - _start;

                //size_t newcapacity = capacity() == 0 ? 4 : 2 * capacity();
                reserve(0 ? 4 : 2 * capacity());
                pos = _start + len;
            }
            iterator it = _finish - 1;
            while (it != pos)
            {
                *(it + 1) = *it;
                --it;
            }
            *it = x;
            ++_finish;
            return pos;
        }

        iterator erase(iterator pos)//迭代器失效
        {
            assert(pos >= _start && pos < _finish);
            auto Old_Pos = pos;
            while (pos != end())
            {
                *pos = *(pos + 1);
                ++pos;
            }
            --_finish;
            return Old_Pos;
        }

    private:
        iterator _start = nullptr; 
        iterator _finish = nullptr; 
        iterator _endOfStorage = nullptr; 
    };
}