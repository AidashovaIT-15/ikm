//source_stack.cpp
#include<string>
#include<iostream>
#include<vector>
#include "mstack.h"
using namespace std;
struct SNode
{
    string val;//операнд
    SNode* next;//указатель на следующий элемент
};
class Opers//хранение операндов 
{
private:
    SNode* top;//вершина стека
    int tempc;//счёчик временных епременных
public:
    Opers()
    {
        top = NULL;
        tempc = 1;
    }
    void push(string val)//добавление элемента  
    {
        SNode* newNode = new SNode;
        newNode->val = val;
        newNode->next = top;
        top = newNode;
    }
    string pop()//извлечение элемента 
    {
        if (top == NULL)
        {
            return ""; // Стек пуст
        }
        SNode* tn = top;
        string val = top->val;
        top = top->next;
        delete tn;
        return val;
    }
    bool emp()//проверка на пустоту
    {
        return top == NULL;
    }
    string t()//новая временная переменная 
    {
        return "T" + to_string(tempc++);
    }
};
bool operd(char d)//проверка на операнд 
{
    return d == '+' || d == '-' || d == '*' || d == '/';
}
bool opert(char d)//проверка на оператор
{
    return (d >= 'A' && d <= 'Z') || (d >= 'a' && d <= 'z');
}
bool corr(string& expr)//проверка корректности выражения 
{
    int operc = 0;
    for (char d : expr)
    {
        if (operd(d))
        {
            operc++;
        }
        else if (opert(d))
        {
            if (operc < 2)
            {
                return false;
                operc--;
            }
        }
        else
        {
            return false;//некорректный символ
        }
    }
    return operc == 1;
}
vector<string> convinst(string& expr)//преобразование выражения 
{
    Opers stack;
    vector<string> inst;
    for (char d : expr)
    {
        if (operd(d))
        {
            stack.push(string(1, d));//добавление операнда в стек
        }
        else if (opert(d))
        {
            string oper2 = stack.pop();//два операнда из стека
            string oper1 = stack.pop();
            string temp = stack.t();//новая переменная
            inst.push_back(" LD " + op1);//инструкции
            switch (d)
            {
            case '+':
                inst.push_back(" AD " + oper2);
                break;
            case '-':
                inst.push_back(" SB " + oper2);
                break;
            case '*':
                inst.push_back(" ML " + oper2);
                break;
            case '/':
                inst.push_back(" DV " + oper2);
                break;
            }
            inst.push_back(" ST " + temp);
            stack.push(temp);//временная переменная в стеке
        }
    }
