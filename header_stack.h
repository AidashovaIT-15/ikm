//header.h
#include<iostream>
#include<vector>
using namespace std;
void push(string val);//добавление 
string pop();
bool emp();//проверка на пустоту
string gett();
bool operd(char d);//проверка на операнд
bool opert(char d);//проверка на оператор
bool corr(string& expr);//проверка на корректность
vector<string> convinst(string& expr);
