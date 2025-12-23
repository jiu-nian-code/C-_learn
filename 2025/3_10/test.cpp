#include <iostream>\

#include<string>

#include<stack>

using namespace std;

int main()
{
    string in("tsirhvtujuzdnwprhoihkzvckc");
    stack<char> sk;
    //cin >> in;
    while (!in.empty())
    {
        if (!sk.empty() && in.back() == sk.top())
        {
            sk.pop();
            in.pop_back();
        }
        else
        {
            sk.push(in.back());
            in.pop_back();
        }
    }
    if (sk.empty())
    {
        cout << 0;
    }
    while (!sk.empty())
    {
        cout << sk.top();
        sk.pop();
    }
    return 0;
}