//stack_ikm.cpp
#include<iostream>
#include<vector>
#include<string>
#include "mstack.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << " Преобразование постфиксных выражений ";
    cout << " Введите выражение(пример: ABC*+DE-/): ";
    string inpexp;
    getline(cin, inpexp);
    string expr;//удаление пробелов
    for (char d : inpexp)
    {
        if (d != ' ') expr += d;
    }
    if (!corr(expr))//проверка на корректность 
    {
        cout << " Ошибка! Некорректное выражение ";
        cout << " Используйте только буквы (A-Z,a-z) и операторы (+ - * /) ";
        cout << " Пример: AB+C* или ABC*+DE-/ ";
        return 1;
    }
    vector<string> inst = convinst(expr);//преобразование выражения
    cout << " Инструкции: ";
    for (string& instr : inst)
    {
        cout << instr << endl;
    }
    return 0;
}
