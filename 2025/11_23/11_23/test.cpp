#pragma once

#include<mutex>

#include <condition_variable>

#include<thread>

#include<vector>

class Threadloop
{
    int* _el;
    std::mutex _mt;
    std::condition_variable _cv;
    std::thread _th;

    void handle_thread()
    {
        int el;
        {
            std::unique_lock<std::mutex> lock(_mt);
            _el = &el;
            _cv.notify_all();
        }
        while (1) {}
    }

public:
    Threadloop() : _el(nullptr), _th(&Threadloop::handle_thread, this) {}

    int* Getint()
    {
        int* tmpel = nullptr;
        {
            std::unique_lock<std::mutex> lock(_mt);
            _cv.wait(lock, [&]() { return _el != nullptr; });
            tmpel = _el;
        }
        return tmpel;
    }
};

class ThreadloopPool
{
    int _thread_num = 0;
    int* _mainloop;
    std::vector<Threadloop*> _thread_arr;
    std::vector<int*> _loop_arr;
    int _next = 0;
public:
    ThreadloopPool(int* ml) : _mainloop(ml) {}

    void Set_Thread_Num(int num) { _thread_num = num; }

    void Init()
    {
        if (_thread_num == 0) return;
        _thread_arr.resize(_thread_num);
        _loop_arr.resize(_thread_num);
        for (int i = 0; i < _thread_num; ++i)
        {
            _thread_arr[i] = new Threadloop();
            _loop_arr[i] = _thread_arr[i]->Getint();
        }
    }

    int* NextLoop()
    {
        if (_thread_num == 0) return _mainloop;
        int ret = _next;
        (++_next) %= _thread_num;
        return _loop_arr[ret];
    }
};

int main()
{
    int a = 1;
    ThreadloopPool* tmp = new ThreadloopPool(&a);
    tmp->Set_Thread_Num(2);
    tmp->Init();
}