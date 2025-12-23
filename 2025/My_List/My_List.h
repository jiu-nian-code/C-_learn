#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

namespace jiunian
{
    // List的节点类
    template<class T>
    struct ListNode
    {
        ListNode(const T& val = T()) :
            _pPrev(nullptr),
            _pNext(nullptr),
            _val(val)
        {
        }
        ListNode<T>* _pPrev;
        ListNode<T>* _pNext;
        T _val;
    };

    //List的迭代器类
    template<class T, class Ref, class Ptr>
    struct ListIterator
    {
        typedef ListNode<T>* PNode;
        typedef ListIterator<T, Ref, Ptr> Self;
        ListIterator(PNode pNode = nullptr):
            _pNode(pNode)
        {
        }

        ListIterator(const Self& l):
            _pNode(l._pNode)
        {
        }

        Ref operator*()
        {
            return _pNode->_val;
        }

        Ptr operator->()
        {
            return &(_pNode->_val);
        }

        Self& operator++()
        {
            _pNode = _pNode->_pNext;
            return *this;
        }

        Self& operator++(int)
        {
            Self tmp(*this);
            _pNode = _pNode->_pNext;
            return tmp;
        }

        Self& operator--()
        {
            _pNode = _pNode->_pPrev;
            return *this;
        }

        Self& operator--(int)
        {
            Self tmp(*this);
            _pNode = _pNode->_pPrev;
            return tmp;
        }

        bool operator!=(const Self& l)
        {
            return _pNode != l._pNode;
        }

        bool operator==(const Self& l)
        {
            return _pNode == l._pNode;
        }
        
        PNode _pNode;
    };

    //list类
    template<class T>
    class list
    {
        typedef ListNode<T> Node;
        typedef Node* PNode;
    public:
        typedef ListIterator<T, T&, T*> iterator;
        typedef ListIterator<T, const T&, const T*> const_iterator;
    public:
        ///////////////////////////////////////////////////////////////
        // List的构造 
        list()
        {
            CreateHead();
        }

        list(int n, const T& value = T())
        {
            CreateHead();
            while(n--)
            {
                push_back(value);
            }
        }

        template <class Iterator>
        list(Iterator first, Iterator last)
        {
            CreateHead();
            while (first != last)
            {
                push_back(*(first++));
            }
        }

        list(const list<T>& l)
        {
            CreateHead();
            for (auto& e : l)
            {
                push_back(e);
            }
        }

        list<T>& operator=(list<T> l)
        {
            swap(l);
            return *this;
        }

        ~list()
        {
            clear();
            delete _pHead;
            _pHead = nullptr;
        }

        ///////////////////////////////////////////////////////////////
        // List Iterator
        iterator begin()
        {
            return _pHead->_pNext;
        }

        iterator end()
        {
            return _pHead;
        }

        const_iterator begin()const
        {
            return _pHead->_pNext;
        }

        const_iterator end()const
        {
            return _pHead;
        }

        ///////////////////////////////////////////////////////////////
        // List Capacity
        size_t size()const
        {
            return _size;
        }

        bool empty()const
        {
            return _pHead == _pHead->_pNext;//size == 0;
        }

        ////////////////////////////////////////////////////////////
        // List Access
        T& front()
        {
            return _pHead->_pNext->_val;
        }

        const T& front()const
        {
            return _pHead->_pNext->_val;
        }

        T& back()
        {
            return _pHead->_pPrev->_val;
        }

        const T& back()const
        {
            return _pHead->_pPrev->_val;
        }

        ////////////////////////////////////////////////////////////
        // List Modify
        void push_back(const T& val)
        { 
            insert(end(), val); 
        }

        void pop_back() 
        {
            erase(--end()); 
        }

        void push_front(const T& val)
        {
            insert(begin(), val); 
        }

        void pop_front() 
        {
            erase(begin()); 
        }

        // 在pos位置前插入值为val的节点
        iterator insert(iterator pos, const T& val)
        {
            Node* newnode = new Node(val);
            newnode->_pPrev = pos._pNode->_pPrev;
            newnode->_pNext = pos._pNode;
            pos._pNode->_pPrev->_pNext = newnode;
            pos._pNode->_pPrev = newnode;
            ++_size;
            return newnode;
        }

        //iterator insert(iterator pos, const T& x)
        //{
        //    Node* cur = pos._pNode;
        //    Node* prev = cur->_pPrev;
        //    Node* newnode = new Node(x);
        //    prev->_pNext = newnode;
        //    newnode->_pNext = cur;
        //    cur->_pPrev = newnode;
        //    newnode->_pPrev = prev;
        //    //++_size;
        //    return newnode;
        //}

        // 删除pos位置的节点，返回该节点的下一个位置
        iterator erase(iterator pos)
        {
            pos._pNode->_pNext->_pPrev = pos._pNode->_pPrev;
            pos._pNode->_pPrev->_pNext = pos._pNode->_pNext;
            iterator ret = pos._pNode->_pNext;
            delete pos._pNode;
            --_size;
            return ret;
        }

        void clear()
        {
            iterator cur = begin();
            while (cur != end())
            {
                cur = erase(cur);
            }
            _size = 0;
        }

        void swap(list<T>& l)
        {
            std::swap(_pHead, l._pHead);
            std::swap(_size, l._size);
        }

    private:
        void CreateHead()
        {
            _pHead = new Node;
            _pHead->_pNext = _pHead;
            _pHead->_pPrev = _pHead;
        }
        PNode _pHead;
        size_t _size = 0;
    };
};