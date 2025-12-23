#include<iostream>

#define Separator_Spa ' '

#define Separator_Pro '\n'

std::string encode(std::string msg)
{
    std::string ret = std::to_string(msg.size());
    ret += Separator_Pro;
    ret += msg;
    ret += Separator_Pro;

    return ret;
}

bool decode(std::string& msg, std::string& content)
{
    size_t pos = msg.find(Separator_Pro);
    if (pos == std::string::npos) return false;
    std::string szstr = msg.substr(0, pos);
    size_t sz = std::stoi(szstr);
    size_t totalsz = sz + szstr.size() + 2;
    if (totalsz < msg.size()) return false;
    content = msg.substr(pos + 1, sz);
    msg.erase(0, totalsz);

    return true;
}

class Request
{
public:
    bool Serialization(std::string& message)
    {
        message += std::to_string(_a);
        message += Separator_Spa;
        message += _op;
        message += Separator_Spa;
        message += std::to_string(_b);

        return true;
    }

    bool Deserialization(std::string& msg)
    {
        size_t left = msg.find(Separator_Spa);
        if (left == std::string::npos) return false;
        _a = std::stoi(msg.substr(0, left));
        size_t right = msg.find(Separator_Spa, left + 1);
        if (right == std::string::npos) return false;
        _op = msg[left + 1];
        _b = std::stoi(msg.substr(right + 1));

        return true;
    }

    int _a;
    int _b;
    char _op;
};

class Response
{
public:
    bool Serialization(std::string& message)
    {
        message += std::to_string(_result);
        message += Separator_Spa;
        message += std::to_string(_status_code);

        return true;
    }

    bool Deserialization(std::string& msg)
    {
        size_t mid = msg.find(Separator_Spa);
        if (mid == std::string::npos) return false;
        _result = std::stoi(msg.substr(0, mid));
        _status_code = std::stoi(msg.substr(mid + 1));

        return true;
    }

    int _result = 0;
    int _status_code = 0;
};