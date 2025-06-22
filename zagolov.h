//zagolov.h
#include<iostream>
#include<vector>
using namespace std;
bool oper(char c);//функция проверки символа на оператор
bool let(char c);//функция проверки символа на операнд
void remsp(string& str);//функция для удаления пробелов
bool corr(string& expr);//функция проверки выражения на корректность
vector<string> geninstr(string& expr);//функция для генерации инструкций
