//Реализовать полнофункциональную систему тестирования.

//В системе должны быть реализовано 2 режима:
 //Администратор;
 //Тестируемый.
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <windows.h>
#include <conio.h>

#include <stdio.h>
#include <sys/types.h>
#include <io.h>

using namespace std;

const int key = -5;         // ключ кодирования паролей  внести в отдельный файл...

string Key(string str);
string KeyLock(string str);
string log(int k);
string pas(int fl, int k);
void ChangeFile(string& s, string l, string p);
