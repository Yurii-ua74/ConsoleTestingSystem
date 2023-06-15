#include "Main.h"
#include "User.h"

vector <User> uservec;
User user;

void User::CreateUser(int n, int it)           // n == 1 - ввод виртуальных пользователей 2 - ввод пользоватнля вручную в конец списка  3 - для вставки ползователя в списоk после модификации
{                                              // it - итератор модифицируемого пользователя  0 - для других случаев
		cout << "Введите имя пользователя\n";	
		cin >> name;
		cout << "Введите фамилию пользователя\n";
		cin >> surname;
		cout << "Введите дату рождения пользователя\n";
		cin >> birth;
		cout << "Введите номер телефона пользователя\n";
		cin >> phonumb;
		cout << "Введите адрес проживания пользователя :\n";
		cout << "Город - "; cin >> city;
		cout << "Улица - "; cin >> street;
		cout << "Номер дома - "; cin >> house;
		cout << "Номер квартиры - "; cin >> flat;
		cout << "Создадим учетную запись \n";
		us_log = log(1);                       // 1 - шифрование  2 - дешифрование
		this->x = 1;
		us_pas = pas(this->x, 1);
        if (n == 2)                            // для ввода пользоватнля в конец списка
		uservec.push_back(User(us_log, us_pas, phonumb, name, surname, birth, city, street, house, flat));
		if (n == 3)                            // для вставки ползователя в списоk после модификации
		{
			//auto iter = uservec.cbegin();   // константный итератор указывает на первый элемент
			//uservec.emplace(iter + it, User(us_log, us_pas, phonumb, name, surname, birth, city, street, house, flat));  // вставит данные пользователя (не используется по условиям задачи)

			uservec.at(it) = User(us_log, us_pas, phonumb, name, surname, birth, city, street, house, flat);           //  изменить данные пользователя
		}
	char S;
	cout << "Распечатать данные пользователей?  \"Y\" or \"N\" : ";
	cin >> S;
	cout << endl;
	if (S == 'Y' || S == 'y' || S == 'Н' || S == 'н')
		user.Show();
	char SS;
	cout << "Внести данные пользователей в файл?  \"Y\" or \"N\" : ";
	cin >> SS;
	if (SS == 'Y' || SS == 'y' || SS == 'Н' || SS == 'н')
	{
		ofstream adout("log_user.txt");                 // открыть  файл 
		if (!(adout.is_open()))                         // проверка открытия файлов
		{
			cout << "файл не найден или поврежден\n";   // если с файлом какие то ошибки или не найден
		}
		else
		{
			int i = 1;
			for (User n : uservec) 
			{		
				adout << n.us_log << endl;
				adout << n.us_pas << endl;
				adout << n.name << endl;
				adout << n.surname << endl;
				adout << n.phonumb << endl;
				adout << n.birth << endl;
				adout << n.city << endl;
				adout << n.street << endl;
				adout << n.house << endl;
				adout << n.flat << endl;
				std::cout << std::endl;
			}
		}
		adout.close();
	}
}

int User::FindUser()
{
	string _name, _surname, _phonumber;
	cout << "Введите имя  пользователя : ";
	cin >> _name;
	cout << "Введите фамилию  пользователя : ";
	cin >> _surname;
	cout << "Введите номер телефона  пользователя : ";
	cin >> _phonumber;
	for (int i = 0; i < uservec.size(); i++)            // сравнивает введенные данные с имеющимися в контейнере
	{		
		if (uservec[i].name == _name &&
			uservec[i].surname == _surname &&
			uservec[i].phonumb == _phonumber)
			return i;                                   // при совпадении возвращает итератор
	}
	//for_each(uservec.begin(), uservec.end(), show);   //  не пошло
	return -1;
}

void User::Show()
{
	for (int i = 0; i < uservec.size(); i++)
	{
		cout << "Пользователь " << "# " << i + 1 << endl;				
		cout << uservec[i].name << endl;
		cout << uservec[i].surname << endl;
		cout << uservec[i].phonumb << endl;
		cout << uservec[i].birth << " г.р." << endl;
		cout << "город " << uservec[i].city << endl;
		cout << "ул. " << uservec[i].street << endl;
		cout << "дом " << uservec[i].house << endl;
		cout << "кв. " << uservec[i].flat << endl;
		cout << endl;
	}
	int xx = _getch();
}

void User::ShowOne(int i)
{
		cout << "Пользователь " << "# " << i + 1 << endl;
		cout << uservec[i].name << endl;
		cout << uservec[i].surname << endl;
		cout << uservec[i].phonumb << endl;
		cout << uservec[i].birth << " г.р." << endl;
		cout << "город " << uservec[i].city << endl;
		cout << "ул. " << uservec[i].street << endl;
		cout << "дом " << uservec[i].house << endl;
		cout << "кв. " << uservec[i].flat << endl;
	int xx = _getch();
}

void User::RegistrUser()
{
	user.CreateUser(2, 0);
}

bool User::LogInUser()                              // вход пользователя в систему
{
	string temp_log;
	string temp_pas;	
	ifstream adin("log_user.txt");                  // открыть файл для чтения
	if (!adin.is_open())
	{
		cout << "файл не найден или поврежден\n";   // если файл не найден или поврежден
	}
	else
	{
		temp_log = log(2);
		temp_pas = pas(0,2);
		string ch;
		int i = 0;
		int j = 0;
		// прочитаем с файла 	
		do
		{
			ch = "";
			i++;
			if (i == 1)
			{
				(getline(adin, ch));
				this->us_log = Key(ch);
				if (this->us_log == temp_log)
				{
					(getline(adin, ch));
					this->us_pas = Key(ch);
					if (this->us_pas == temp_pas)
					{
						(getline(adin, this->name));
						(getline(adin, this->surname));
						system("cls");
						cout << "Добро пожаловать на тестирование " << this->name << " " << this->surname << endl;
						adin.close();
						return true;
					}
					else cout << "Не правильно введен пароль\n";
					adin.close();
					return false;
				}
				else cout << "Пользователя с таким логином не зарегистрировано\n";                              //cout << "Пользователя с именем " << temp_log << "не найдено!!! ";
				adin.close();
				return false;
			}			
			
		} while (ch != "");
		adin.close();			
	}
	return false;
}


void User::EraseUser()
{
	if (uservec.size() == 0) { cout << "Не зарегистрировано ниодного пользователя \n"; int xx = _getch(); }
	else
	{
		char S;
		int it = FindUser();
		auto iter = uservec.cbegin();                      // указатель на первый элемент
		uservec.erase(iter + it);                          // удаляем элемент
		cout << "Распечатать остаток?  \"Y\" or \"N\" : ";
		cin >> S;
		if (S == 'Y' || S == 'y' || S == 'Н' || S == 'н')
			user.Show();
	}
}

void User::ModifyUser()
{
	if (uservec.size() == 0) { cout << "Не зарегистрировано ниодного пользователя \n"; int xx = _getch(); }
	else
	{
		int it = FindUser();
		user.ShowOne(it);
		user.CreateUser(3, it);		
	}
}
