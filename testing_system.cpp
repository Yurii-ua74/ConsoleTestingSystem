//����������� ������������������� ������� ������������.

//� ������� ������ ���� ����������� 2 ������:
 //�������������;
 //�����������.

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
		cout << " ����� ���������� � ������� ������������\n\n";
		cout << "   " << "1-�������������" << "\t2-�����" << endl;
		cout << "\t0 - ������� ��������� \n";
		cin >> x;
		if (x == 1)           // ��� ������ ��������������
		{
			int y = 0;
			int res = 0;

			do
			{
				system("cls");
				res = 0;
				cout << "\t  �������������  \n";
				cout << " " << "1-������������������ " << "\t2-�����" << endl;
				cin >> y;
				admin.SetY(y);
				switch (y)
				{
				case 1:          // ����������� ������
				{
					res = admin.registration();
					switch (res)
					{
					case 0: cout << "���� c ������������ �� ������\n"; break;
					case 1: cout << "������� ������ �������������� ��� �������\n"; break;
					case 2: cout << "����������� �������������� ��������� �������\n"; break;
					}
					int xx = _getch();
				}
				case 2:          // ���� ������
				{
					int res1 = 0;
					do
					{
						if (res != 0 || y == 2)
						{
							res1 = 0;
							system("cls");
							cout << "��� ����� ������� ����� � ������ �������������� \n";
							admin.SetY(2);
							res1 = admin.LogIn();
							switch (res1)
							{
							case 0: cout << "���� c ������������ �� ������ ��� ��������� \n"; break;
							case 1: cout << "����������� ������ ����� �������������� \n"; break;
							case 2: cout << "����������� ������ ������ �������������� \n"; break;
							case 3: {
								system("cls");
								cout << "�� ��������� ���� � ������� ������ �������������� \n";
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
				cout << "     " << "��������������\n";
				cout << "1 - ������� ����� ��� ������ \n";
				cout << "2 - ���������� �������������� \n";
				cout << "3 - �������� ���������� \n";
				cout << "4 - ���������� ������������� \n";
				cout << "0 - ����� �������������� \n";
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
		else if (x == 2)      // ��� ������ �����
		{
			system("cls");
			int k;
			cout << "\t � � � � � \n";
			cout << " " << "1-������������������ " << "\t2-�����" << endl;
			cin >> k;
			if (k == 1)       // ����������� �����
			{
				system("cls");
				users.RegistrUser();
			}
			else if (k == 2)  // ���� �����
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
			else cout << "����� �����!\n";
		}
		else cout << "Good by!!!\n";
	}while (x != 0);
	

	return 0;
}