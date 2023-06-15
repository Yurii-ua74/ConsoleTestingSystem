//Реализовать полнофункциональную систему тестирования.

//В системе должны быть реализовано 2 режима:
 //Администратор;
 //Тестируемый.

#include "Main.h"
#include "Admin.h"
#include "User.h"
#include "Test.h"

string name;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int x = 0;
	Admin admin;
	User users;
	Test test;
	do
	{
		system("cls");
		cout << " добро пожаловать в систему тестирования\n\n";
		cout << "   " << "1-АДМИНИСТРАТОР" << "\t2-ГОСТЬ" << endl;
		cout << "\t0 - Закрыть программу \n";
		cin >> x;
		if (x == 1)           // код работы администратора
		{
			int y = 0;
			int res = 0;

			do
			{
				system("cls");
				res = 0;
				cout << "\t  АДМИНИСТРАТОР  \n";
				cout << " " << "1-Зарегистрироваться " << "\t2-Войти" << endl;
				cin >> y;
				admin.SetY(y);
				switch (y)
				{
				case 1:          // регистрация админа
				{
					res = admin.registration();
					switch (res)
					{
					case 0: cout << "Файл c регистрацией не найден\n"; break;
					case 1: cout << "Учетная запись АДМИНИСТРАТОРА уже имеется\n"; break;
					case 2: cout << "Регистрация АДМИНИСТРАТОРА проведена успешно\n"; break;
					}
					int xx = _getch();
				}
				case 2:          // вход админа
				{
					int res1 = 0;
					do
					{
						if (res != 0 || y == 2)
						{
							res1 = 0;
							system("cls");
							cout << "Для входа введите логин и пароль администратора \n";
							admin.SetY(2);
							res1 = admin.LogIn();
							switch (res1)
							{
							case 0: cout << "Файл c регистрацией не найден или поврежден \n"; break;
							case 1: cout << "Неправильно введен логин АДМИНИСТРАТОРА \n"; break;
							case 2: cout << "Неправильно введен пароль АДМИНИСТРАТОРА \n"; break;
							case 3: {
								system("cls");
								cout << "Вы совершили вход в учетную запись АДМИНИСТРАТОРА \n";
								admin.SetFlagAdmin(1);
							}
							}
						}
						//system("pause");                
						int xx = _getch();
					} while (res1 < 3);
				}
				}
				//system("pause");
				//int xx = _getch();
			} while (y == 0);
			int choice = 0;
			do
			{
				system("cls");
				cout << "\tM E N U \n";
				cout << "     " << "Администратора\n";
				cout << "1 - Сменить логин или пароль \n";
				cout << "2 - Управление пользователями \n";
				cout << "3 - Просмотр статистики \n";
				cout << "4 - Управление тестированием \n";
				cout << "0 - Выход администратора \n";
				cin >> choice;
				switch (choice)
				{
				case 0: {} break;
				case 1:
				{
					system("cls");
					admin.ChangeLogPass();
				}
				break;
				case 2:
				{
					system("cls");
					admin.UserManagement();
				}
				break;
				case 3:
				{
					//  admin.LookStat();           //
				}
				break;
				case 4:
				{
					system("cls");
					admin.TestManagement();
				}
				break;

				}

			} while (choice != 0);
		}
		else if (x == 2)      // код работы гостя
		{
			system("cls");
			int k;
			cout << "\t Г О С Т Ь \n";
			cout << " " << "1-Зарегистрироваться " << "\t2-Войти" << endl;
			cin >> k;
			if (k == 1)       // регистрация гостя
			{
				system("cls");
				users.RegistrUser();
			}
			else if (k == 2)  // вход гостя
			{
				system("cls");
				bool flag = users.LogInUser(); 
				if (flag == true)
				{
					name = users.Getname() + " " + users.Getsurname();
					test.Setname2(name);
					test.TestChoice();				
				}
				system("pause");
			}
			else cout << "Выход гостя!\n";
		}
		else cout << "Good by!!!\n";
	}while (x != 0);
	

	return 0;
}