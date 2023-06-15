//Реализовать полнофункциональную систему тестирования.

//В системе должны быть реализовано 2 режима:
 //Администратор;
 //Тестируемый.
#include "Main.h"

void ChangeFile(string& s, string l, string p) // преданы название файла, логин и пароль
{
	ofstream adout(s);                         // открыть  файл для замены информации
	if (!adout.is_open())
	{
		cout << "Файл не найден или поврежден\n";
	}
	else
	{
		adout << l << endl;              // запись в файл нового логина
		adout << p << endl;              // запись в файл нового пароля
	}
	adout.close();
}

string log(int k)                              // регистрация или ввод логина
{
	string log;
	cout << "Введите логин \n";
	do
	{
		getline(cin, log);
	} while (log == "");
	if(k == 1)  return KeyLock(log);           //log + key;    1 - шифрование  
	if(k == 2)  return log;
	return "error";
}

string pas(int fl, int k)                      // регистрация или ввод пароля (в функцию передан флаг регистрация пароля или ввод существующего)
{
	int cnt = 0;                        // общее кол-во символов в пароле
	int num = 0;                        // кол-во цифр
	int sml = 0;                        // кол-во мал букв
	int grn = 0;                        // кол-во бол букв
	string pas1;                        // этот пароль будет введен первый при регистрации
	string pas2;                        // этот пароль будет введен вторым при регистрации
	do
	{
		cout << "Введите пароль\n(не меньше 5 символов состояший из букв маленьких, больших и цифр) \n";
		do
		{
			getline(cin, pas1);
		} while (pas1 == "");
		// разберу string на символы и проверю на соответствие пароля требованиям
		for (int i = 0; i != pas1.size(); i++)
		{
			if (pas1.at(i) > 47 && pas1.at(i) < 58) num++;     // есть ли в пароле цифры
			if (pas1.at(i) > 64 && pas1.at(i) < 91) grn++;     // есть ли большие буквы
			if (pas1.at(i) > 96 && pas1.at(i) < 123) sml++;    // есть ли маленькие буквы
		}
		cnt = num + grn + sml;                                 // сколько символов в пароле
	} while (cnt < 5 && num == 0 && grn == 0 && sml == 0);
	if (fl == 1)                                               // если флаг указывает не на вход с имеющимся паролем (т.е. в меню выбран пункт 1) 
	{                                                          // fl == 1 - регистрация / 0 - вжод в систему
		int equ = 0;                                           // переменная равенства паролей
		do
		{
			if (cnt >= 5 && num > 0 && grn > 0 && sml > 0)
			{
				cout << "Введите пароль для подтверждения\n";
				getline(cin, pas2);
			}
			equ = pas1.compare(pas2);                          // сравнивание дважды введенного пароля
			if (equ == 0)
				cout << "Пароль подтвержден\n";
			else cout << "Пароли не совпадают\n";
		} while (equ != 0);
	}
	if (k == 1)  return KeyLock(pas1);                         //  1 - шифрование  
	if (k == 2)  return pas1;
	return "error";
}

string Key(string str)                                         // для дешифрования пароля
{
	for (int i = 0; i != str.size(); i++)
	{
		str.at(i) = str.at(i) - key;
	}
	return str;
}

string KeyLock(string str)                                    // для шифрования пароля
{
	for (int i = 0; i != str.size(); i++)
	{
		str.at(i) = str.at(i) + key;
	}
	return str;
}