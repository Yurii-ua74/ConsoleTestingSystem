#pragma once
#include "Main.h"



class User
{
	string us_log;            // логин пользователя
	string us_pas;            // пароль пользователя
	string phonumb;           // номер телефона
	string name;              // имя
	string surname;           // фамилия
	string  birth;            // дата рождения
	string	city;             // город проживания
	string	street;           // улица
	int 	house;            // дом
	int 	flat;             // квартира
	
public:
	int x = 0;                // flag

	User()
	{
		us_log = "";
		us_pas = "";
		phonumb = "";
		name = "";
		surname = "";
		birth = "";
		city = "";
		street = "";
		house = 0;
		flat = 0;        
	};

	User(
		string  us_log,
		string  us_pas,
		string  phonumb,
		string  name,
		string  surname,
		string  birth,
		string	city,
		string	street,
		int 	house,
		int 	flat
	)
	{
		this->us_log = us_log;
		this->us_pas = us_pas;
		this->phonumb = phonumb;
		this->name = name;
		this->surname = surname;
		this->birth = birth;
		this->city = city;
		this->street = street;
		this->house = house;
		this->flat = flat;
	};
	string Getus_log() { return us_log; }
	string Getname() { return name; }
	string Getsurname() { return surname; }
	void CreateUser(int n, int it);      // сoздание пользователя
	void EraseUser();               // метод удаления пользователя
	void ModifyUser();              // метод для изменения данных пользователя
	int FindUser();                 // ищет пользователя Б возвращает итератор
	void Show();                    // плказать всех рользователей
	void ShowOne(int i);            // показать выбранного пользователя
	void RegistrUser();             // регистрация пользователя
	bool LogInUser();               // вход пользователя
};
