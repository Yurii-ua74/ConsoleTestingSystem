#pragma once
#include "Main.h"



class Admin
{
	string  login;             // логин админа
	string  password;          // пароль админа
	int flag_admin;            // флаг админ или нет
	int y;                     // флаг регистрация или вход в систему
	
public:
	Admin() :login(""), password(""), flag_admin(0), y(0) {};
	Admin(string login, string password, int flag_admin, int y)
		:login(login), password(password), flag_admin(flag_admin), y(y) {};

	void SetFlagAdmin(int a) { flag_admin = a; }          // флаг админ или нет  ввод
	void SetY(int a) { y = a; }                           // флаг регистрация или вход в систему ввод
	int GetFlagAdmin() { return flag_admin; }             // флаг админ или нет  вывод
	int GetY() { return y; }                              // флаг регистрация или вход в систему вывод
	int registration();                                   // метод регистрации Админа
	int LogIn();                                          // метод идентификации по логину и паролю
	void ChangeLogPass();                                 // метод смены логина и пароля
	void UserManagement();                                // метод управления пользователями
	void TestManagement();                                // иетод управления тестированием
	void AddTXT();                                        // добавление текста теста
	void EditTXT();                                       // редактирование, перезапись текста
	void Category();
	void Tests(string tst);
	void ShowCategory();
	string FindTest(string choice_category, int choice_test);
	//void ShowTests();
};

//Admin admin;