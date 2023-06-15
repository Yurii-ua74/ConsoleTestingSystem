#include "Main.h"
#include "Admin.h"
#include "User.h"

string str_cat;
map <int, string> MapMath;                                             // объявил map для тестов 	
map <int, string> MapPhys;
map <int, string> MapChem;
map <int, string> MapDiff;
map <int, string> MapOther;
multimap <string, map <int, string>> MapСategory;                      // объявил multimap для категорий

int Admin::registration()                      // регистрация админа
{
	string str;
	ofstream adout("log_admin.txt", ios::app); // открыть и закрыть файл а в случае его отсутствия создать
	adout.close();
	ifstream adin("log_admin.txt");            // открыть файл для чтения
	if (!adin.is_open())
	{
		return 0;                              // если файл не найден
	}
	else
	{
		char ch;
		if (adin.get(ch)) 
		{ adin.close(); return 1; }            // если в этом файле что то есть значит учетнаЯ запись АДМИН уже существует
		else
		{		
			adin.close();
			ofstream adout("log_admin.txt", ios::app);
			if (!(adout.is_open()))                    // проверка открытия файлов
			{
				return 0;                              // если с файлом какие то ошибки или не найден
			}
			else
			{
				adout << log(1) << endl;                // запись в файл устанавливаемого логина  1 - шифрование  2 - дешифрование
				adout << pas(this->y, 1) << endl;       // запись в файл устанавливаемого пароля
			}
			adout.close();
		}	
	}
	return 2;                                          // если логтн и пароль успешно введены
}

int Admin::LogIn()                             // вход Админа в систему
{
	string temp;
	ifstream adin("log_admin.txt");            // открыть файл для чтения
	if (!adin.is_open())
	{
		return 0;                              // если файл не найден или поврежден
	}
	else
	{
		string ch;
		int i = 0;
		// прочитаем с файла логин и пароль Админа		
		do
		{
			ch = "";
			i++;
			if (i == 1)
			{
				(getline(adin, ch));
				this->login = Key(ch);
			}
			else if (i == 2)
			{
				(getline(adin, ch));
				this->password = Key(ch);
			}
		} while (ch != "");
		
		adin.close(); 
	}
	temp = log(2);                                       // введенный при входе логин  1 - шифрование  2 - дешифрование
	for (int i = 0; i != login.size(); i++)
	{
		if (temp.size() == login.size()
			&&  temp.at(i) == login.at(i)) continue;     // сравним логин введенный при входе и при регистрации
		else return 1;
	}
	temp = pas(this->y, 2);
	for (int i = 0; i != password.size(); i++)
	{
		if (temp.size() == password.size()
			&& temp.at(i) == password.at(i)) continue;   // сравним пароль введенный при входе и при регистрации
		else return 2;
	}
	return 3;
}

void Admin::ChangeLogPass()
{
	//Admin admin;
	int change = 0;
	do
	{
	    cout << "\tЧто хотите сменить? \n";
	    cout << " 1 - Логин " << "\t2 - Пароль" << "\t3 - Ничего\n";
	    cin >> change;
		if (change == 1)
		{		
			cout << "Смена логина\n";
			login = log(1);                            // установлен новый логин     1 - шифрование  2 - дешифрование
			cout << "Логин изменен\n";
		}
		else if (change == 2)
		{
			cout << "Смена пароля\n";
			y = 1;                                     // флаг в 1 (смена или установка пароля)
			password = pas(this->y, 1);                // установлен новый пароль
			cout << "Пароль изменен\n";
		}
		string st = "log_admin.txt";                 
		ChangeFile(st, login, password);               // запись в файл с удалением старой записи
	} while (change > 0 && change < 3);
}

void Admin::UserManagement()
{
	// создание, удаление, модификация пользователей
	int choice = 0;
	User us;
	do
	{
		system("cls");
		cout << "\tM E N U  раздела \n";
		cout << "  " << "Управление пользователями\n";
		cout << "1 - создание \n";
		cout << "2 - удаление \n";
		cout << "3 - модификация \n";
		cout << "0 - Выход из раздела \n";
		cin >> choice;
		switch (choice)
		{
		case 0: {cout << "Работа с разделом закончена\n"; break; }
		case 1:
		{
			system("cls");
			cout << "Создать пользователя\n";			
			us.CreateUser(2, 0);
		}
		break;
		case 2:
		{
			system("cls");
			cout << "Удалить пользователя\n";
			us.EraseUser();
		}
		break;
		case 3:
		{
			system("cls");
			cout << "Модифицировать пользователя\n";
			us.ModifyUser();
		}
		break;
		}
	} while (choice != 0);
}

void Admin::TestManagement()
{

	int choice = 0;
	User us;
	do
	{
		system("cls");
		cout << "\tM E N U  раздела \n";
		cout << "  " << "Управление тестированием\n";
		cout << "1 - выбрать/добавить категорию \n";
		cout << "2 - добавить тест \n";
		cout << "3 - редактировать тест \n";
		cout << "0 - Выход из раздела \n";
		cin >> choice;
		switch (choice)
		{
		case 0: {cout << "Работа с разделом закончена\n"; break; }
		case 1:
		{
			system("cls");
			char chce;
			//if(MapСategory.empty())                                            //////////////////////////////////////////////////////////////////
			Admin::Category();
			cout << "имеются следующие категории : \n";
			Admin::ShowCategory();
			cout << "Добавить еще категорию?   \"Y\" or \"N\" : ";
			cin >> chce;
			if (chce == 'Y' || chce == 'y' || chce == 'Н' || chce == 'н')
			{
			    str_cat = "";
				cout << "введите наименование добавляемой категории : \n";
				do
				{
					getline(cin, str_cat);
				} while (str_cat == "");
				MapСategory.insert(pair<string, map <int, string>>(str_cat, MapOther));
				cout << " Добавьте имя теста для создания файла : ";
				string tst;
				do
				{
					getline(cin, tst);
				} while (tst == "");
				cout << " и номер файла в категории: "; 
				int N;
				cin >> N;
				MapOther.insert(pair<int, string>(N, tst));
				cout << " Категория добавлена !!! \n";
			}			
			int xx = _getch();
		}
		break;
		case 2:
		{
			system("cls");
			char chce;
			cout << "\tДобавить тест!!!\n\n";
			cout << " Перед добавлением просмотреть список имеющихся тестов?  \"Y\" or \"N\" : ";
			cin >> chce;
			if (chce == 'Y' || chce == 'y' || chce == 'Н' || chce == 'н')
			{
				Admin::Tests("All");
			}
			Admin::AddTXT();
			int xx = _getch();
		}
		break;
		case 3:
		{
			system("cls");
			Admin::EditTXT();
		}
		break;
		}
	} while (choice != 0);
}

void Admin::AddTXT()
{
	string strtxt = "";
	cout << "В какой тест добавить текст? : ";
	do
	{
		getline(cin, strtxt);
	} while (strtxt == "");

	ofstream adout(strtxt, ios::app);
	if (!(adout.is_open()))                                     // проверка открытия файлов
	{
		cout << "файл не найден или поврежден\n";               // если с файлом какие то ошибки или не найден
	}
	else
	{
		string str;
		do
		{
			str = "";
			getline(cin, str);
			adout << str << endl;		
		} while (str != "");
	}
	adout.close();
	cout << "Запись закончена \n";
	int xx = _getch();
}

void Admin::EditTXT()
{
	string strtxt = "";
	cout << " какой тест редактировать ? : ";
	do
	{
		getline(cin, strtxt);
	} while (strtxt == "");

	ofstream adout(strtxt);
	if (!(adout.is_open()))                                     // проверка открытия файлов
	{
		cout << "файл не найден или поврежден\n";               // если с файлом какие то ошибки или не найден
	}
	else
	{
		string str;
		do
		{
			str = "";
			getline(cin, str);
			adout << str << endl;
		} while (str != "");
	}
	adout.close();
	cout << "Запись закончена \n";
	int xx = _getch();
}

void Admin::Category()
{
	if (MapСategory.empty())
	{
		MapСategory.insert(pair<string, map <int, string>>("математика", MapMath));     // заполнил контейнер для категорий	
		MapСategory.insert(pair<string, map <int, string>>("физика", MapPhys));
		MapСategory.insert(pair<string, map <int, string>>("химия", MapChem));
		MapСategory.insert(pair<string, map <int, string>>("другое", MapDiff));
		MapMath.insert(pair<int, string>(1, "general.txt"));                            // заполнил контейнер для тестов по категориям	
		MapMath.insert(pair<int, string>(2, "algebra.txt"));
		MapMath.insert(pair<int, string>(3, "geometry.txt"));
		MapPhys.insert(pair<int, string>(1, "mechanics.txt"));
		MapPhys.insert(pair<int, string>(2, "electrical.txt"));
		MapChem.insert(pair<int, string>(1, "biochemistry.txt"));
		MapChem.insert(pair<int, string>(2, "organic.txt"));
		MapChem.insert(pair<int, string>(3, "technical.txt"));
		MapDiff.insert(pair<int, string>(1, "Different.txt"));
	}
}

void Admin::Tests(string tst)
{

	for (auto it = MapСategory.begin(); it != MapСategory.end(); ++it)            //вывод категорий на экран
	{
		if(tst == "All")
		cout << it->first << " : " << endl;

		if (it->first == "математика" && (tst == "математика" || tst == "All"))
		{
			for (auto it = MapMath.begin(); it != MapMath.end(); ++it)
			{
				cout << it->first << " : " << it->second << endl;
				ofstream adout(it->second, ios::app);                        // открыть и закрыть файл а в случае его отсутствия создать
				adout.close();
			}
		}
		if (it->first == "физика" && (tst == "физика" || tst == "All"))
		{
			for (auto it = MapPhys.begin(); it != MapPhys.end(); ++it)
			{
				cout << it->first << " : " << it->second << endl;
				ofstream adout(it->second, ios::app);                        // открыть и закрыть файл а в случае его отсутствия создать
				adout.close();
			}
		}
		if (it->first == "химия" && (tst == "химия" || tst == "All"))
		{
			for (auto it = MapChem.begin(); it != MapChem.end(); ++it)
			{
				cout << it->first << " : " << it->second << endl;
				ofstream adout(it->second, ios::app);                        // открыть и закрыть файл а в случае его отсутствия создать
				adout.close();
			}
		}
		if (it->first == "другое" && (tst == "другое" || tst == "All"))
		{
			for (auto it = MapDiff.begin(); it != MapDiff.end(); ++it)
			{
				cout << it->first << " : " << it->second << endl;
				ofstream adout(it->second, ios::app);                        // открыть и закрыть файл а в случае его отсутствия создать
				adout.close();
			}
		}
		if (it->first == str_cat && (tst == str_cat || tst == "All"))
		{
			for (auto it = MapOther.begin(); it != MapOther.end(); ++it)
			{
				cout << it->first << " : " << it->second << endl;
				ofstream adout(it->second, ios::app);                        // открыть и закрыть файл а в случае его отсутствия создать
				adout.close();
			}
		}
	}
}

void Admin::ShowCategory()
{
	for (auto it = MapСategory.begin(); it != MapСategory.end(); ++it)              //вывод категорий на экран
	{
		cout << it->first << endl;
	}
}

string Admin::FindTest(string choice_category, int choice_test)
{
	string test_name = "No name";
	for (auto it = MapСategory.begin(); it != MapСategory.end(); ++it)            //вывод категорий на экран
	{
		if (it->first == "математика" && choice_category == "математика")
		{
			for (auto it = MapMath.begin(); it != MapMath.end(); ++it)
			{
				if (it->first == choice_test) return it->second;
			}
		}
		if (it->first == "физика" && choice_category == "физика")
		{
			for (auto it = MapPhys.begin(); it != MapPhys.end(); ++it)
			{
				if (it->first == choice_test) return it->second;
			}
		}
		if (it->first == "химия" && choice_category == "химия")
		{
			for (auto it = MapChem.begin(); it != MapChem.end(); ++it)
			{
				if (it->first == choice_test) return it->second;
			}
		}
		if (it->first == "другое" && choice_category == "другое")
		{
			for (auto it = MapDiff.begin(); it != MapDiff.end(); ++it)
			{
				if (it->first == choice_test) return it->second;
			}
		}
		if (it->first == str_cat && choice_category == str_cat)
		{
			for (auto it = MapOther.begin(); it != MapOther.end(); ++it)
			{
				if (it->first == choice_test) return it->second;
			}
		}

	}
	return test_name;
}
