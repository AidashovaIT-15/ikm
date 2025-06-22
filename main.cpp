//stack_ikm.cpp
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "stack.cpp"
using namespace std;
int main() 
{
    setlocale(LC_ALL, "Russian");
    cout << " Введите выражение(пример:ABC*+DE-/) " << endl;
    cout << " Используйте однобуквенные переменные и операторы +, -, *, / " << endl;
    while (true) 
    {
        cout << " - ";
        string inp;
        getline(cin, inp);
        if (inp == " exit ") 
        {
            break;
        }
        remsp(inp);
        if (inp.empty())
        {
            cout << " Ошибка: пустой ввод " << endl;
            continue;
        }
        if (!corr(inp)) 
        {
            cout << " Ошибка: некорректное выражение " << endl;
            cout << " Убедитесь, что: " << endl;
            cout << " 1. Вы используете буквы и операторы:(A-Z),(a-z), (+, -, *, /) " << endl;
            cout << " 2. Операторов на 1 меньше операндов " << endl;
            continue;
        }
        try 
        {
            vector<string> instructions = geninstr(inp);
            cout << " Инструкции: ";
            for (string& instr : instructions) 
            {
                cout << instr << endl;
            }
            cout << endl;

        }
        catch (exception& e) 
        {
            cout << " Ошибка при обработке выражения: " << e.what() << endl;
        }
    }
    cout << " Программа завершена. ";
    return 0;
}
