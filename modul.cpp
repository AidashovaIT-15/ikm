//modul.cpp
#include<iostream>
#include<vector>
#include <string>
using namespace std;
bool oper(char c)//проверка на оператор 
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}
bool let(char c)//проверка на операнд 
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}
void remsp(string& str)//удаление пробелов из строки 
{
    string res;
    for (char c : str)
    {
        if (c != ' ')
        {
            res += c;
        }
    }
    str = res;
}
bool corr(string& expr)//корректность выражения
{
    int letc = 0;
    int operc = 0;
    for (char c : expr)
    {
        if (let(c))
        {
            letc++;
        }
        else if (oper(c))
        {
            operc++;
        }
        else
        {
            return false;//недопустимый символ
        }
    }
    return (letc == operc + 1);
}
class Stack//реализация стека
{
private:
    vector<string> data;
public:
    void push(string& value)
    {
        data.push_back(value);
    }
    string pop()
    {
        if (data.empty())
        {
            throw runtime_error("Stack underflow");
        }
        string val = data.back();
        data.pop_back();
        return val;
    }
    bool empty()
    {
        return data.empty();
    }
    size_t size()
    {
        return data.size();
    }
};
vector<string> geninstr(string& expr)//генерация инструкций
{
    vector<string> instr;
    Stack Let;
    int tempc = 1;
    for (char c : expr)
    {
        if (let(c))
        {
            Let.push(string(1, c));
        }
        else if (oper(c))
        {
            if (Let.size() < 2)
            {
                throw runtime_error(" Invalid expression: not enough operands ");
            }
            string right = Let.pop();
            string left = Let.pop();
            string temp = " T " + to_string(tempc++);
            instr.push_back(" LD " + left);
            switch (c) {
            case ' + ': instr.push_back(" AD " + right); break;
            case ' - ': instr.push_back(" SB " + right); break;
            case ' * ': instr.push_back(" ML " + right); break;
            case ' / ': instr.push_back(" DV " + right); break;
            }
            instr.push_back(" ST " + temp);
            Let.push(temp);
        }
    }
    return instr;
}
