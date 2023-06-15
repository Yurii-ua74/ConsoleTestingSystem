#include "Main.h"
#include "Admin.h"
#include "User.h"

string str_cat;
map <int, string> MapMath;                                             // ������� map ��� ������ 	
map <int, string> MapPhys;
map <int, string> MapChem;
map <int, string> MapDiff;
map <int, string> MapOther;
multimap <string, map <int, string>> Map�ategory;                      // ������� multimap ��� ���������

int Admin::registration()                      // ����������� ������
{
	string str;
	ofstream adout("log_admin.txt", ios::app); // ������� � ������� ���� � � ������ ��� ���������� �������
	adout.close();
	ifstream adin("log_admin.txt");            // ������� ���� ��� ������
	if (!adin.is_open())
	{
		return 0;                              // ���� ���� �� ������
	}
	else
	{
		char ch;
		if (adin.get(ch)) 
		{ adin.close(); return 1; }            // ���� � ���� ����� ��� �� ���� ������ ������� ������ ����� ��� ����������
		else
		{		
			adin.close();
			ofstream adout("log_admin.txt", ios::app);
			if (!(adout.is_open()))                    // �������� �������� ������
			{
				return 0;                              // ���� � ������ ����� �� ������ ��� �� ������
			}
			else
			{
				adout << log(1) << endl;                // ������ � ���� ���������������� ������  1 - ����������  2 - ������������
				adout << pas(this->y, 1) << endl;       // ������ � ���� ���������������� ������
			}
			adout.close();
		}	
	}
	return 2;                                          // ���� ����� � ������ ������� �������
}

int Admin::LogIn()                             // ���� ������ � �������
{
	string temp;
	ifstream adin("log_admin.txt");            // ������� ���� ��� ������
	if (!adin.is_open())
	{
		return 0;                              // ���� ���� �� ������ ��� ���������
	}
	else
	{
		string ch;
		int i = 0;
		// ��������� � ����� ����� � ������ ������		
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
	temp = log(2);                                       // ��������� ��� ����� �����  1 - ����������  2 - ������������
	for (int i = 0; i != login.size(); i++)
	{
		if (temp.size() == login.size()
			&&  temp.at(i) == login.at(i)) continue;     // ������� ����� ��������� ��� ����� � ��� �����������
		else return 1;
	}
	temp = pas(this->y, 2);
	for (int i = 0; i != password.size(); i++)
	{
		if (temp.size() == password.size()
			&& temp.at(i) == password.at(i)) continue;   // ������� ������ ��������� ��� ����� � ��� �����������
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
	    cout << "\t��� ������ �������? \n";
	    cout << " 1 - ����� " << "\t2 - ������" << "\t3 - ������\n";
	    cin >> change;
		if (change == 1)
		{		
			cout << "����� ������\n";
			login = log(1);                            // ���������� ����� �����     1 - ����������  2 - ������������
			cout << "����� �������\n";
		}
		else if (change == 2)
		{
			cout << "����� ������\n";
			y = 1;                                     // ���� � 1 (����� ��� ��������� ������)
			password = pas(this->y, 1);                // ���������� ����� ������
			cout << "������ �������\n";
		}
		string st = "log_admin.txt";                 
		ChangeFile(st, login, password);               // ������ � ���� � ��������� ������ ������
	} while (change > 0 && change < 3);
}

void Admin::UserManagement()
{
	// ��������, ��������, ����������� �������������
	int choice = 0;
	User us;
	do
	{
		system("cls");
		cout << "\tM E N U  ������� \n";
		cout << "  " << "���������� ��������������\n";
		cout << "1 - �������� \n";
		cout << "2 - �������� \n";
		cout << "3 - ����������� \n";
		cout << "0 - ����� �� ������� \n";
		cin >> choice;
		switch (choice)
		{
		case 0: {cout << "������ � �������� ���������\n"; break; }
		case 1:
		{
			system("cls");
			cout << "������� ������������\n";			
			us.CreateUser(2, 0);
		}
		break;
		case 2:
		{
			system("cls");
			cout << "������� ������������\n";
			us.EraseUser();
		}
		break;
		case 3:
		{
			system("cls");
			cout << "�������������� ������������\n";
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
		cout << "\tM E N U  ������� \n";
		cout << "  " << "���������� �������������\n";
		cout << "1 - �������/�������� ��������� \n";
		cout << "2 - �������� ���� \n";
		cout << "3 - ������������� ���� \n";
		cout << "0 - ����� �� ������� \n";
		cin >> choice;
		switch (choice)
		{
		case 0: {cout << "������ � �������� ���������\n"; break; }
		case 1:
		{
			system("cls");
			char chce;
			//if(Map�ategory.empty())                                            //////////////////////////////////////////////////////////////////
			Admin::Category();
			cout << "������� ��������� ��������� : \n";
			Admin::ShowCategory();
			cout << "�������� ��� ���������?   \"Y\" or \"N\" : ";
			cin >> chce;
			if (chce == 'Y' || chce == 'y' || chce == '�' || chce == '�')
			{
			    str_cat = "";
				cout << "������� ������������ ����������� ��������� : \n";
				do
				{
					getline(cin, str_cat);
				} while (str_cat == "");
				Map�ategory.insert(pair<string, map <int, string>>(str_cat, MapOther));
				cout << " �������� ��� ����� ��� �������� ����� : ";
				string tst;
				do
				{
					getline(cin, tst);
				} while (tst == "");
				cout << " � ����� ����� � ���������: "; 
				int N;
				cin >> N;
				MapOther.insert(pair<int, string>(N, tst));
				cout << " ��������� ��������� !!! \n";
			}			
			int xx = _getch();
		}
		break;
		case 2:
		{
			system("cls");
			char chce;
			cout << "\t�������� ����!!!\n\n";
			cout << " ����� ����������� ����������� ������ ��������� ������?  \"Y\" or \"N\" : ";
			cin >> chce;
			if (chce == 'Y' || chce == 'y' || chce == '�' || chce == '�')
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
	cout << "� ����� ���� �������� �����? : ";
	do
	{
		getline(cin, strtxt);
	} while (strtxt == "");

	ofstream adout(strtxt, ios::app);
	if (!(adout.is_open()))                                     // �������� �������� ������
	{
		cout << "���� �� ������ ��� ���������\n";               // ���� � ������ ����� �� ������ ��� �� ������
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
	cout << "������ ��������� \n";
	int xx = _getch();
}

void Admin::EditTXT()
{
	string strtxt = "";
	cout << " ����� ���� ������������� ? : ";
	do
	{
		getline(cin, strtxt);
	} while (strtxt == "");

	ofstream adout(strtxt);
	if (!(adout.is_open()))                                     // �������� �������� ������
	{
		cout << "���� �� ������ ��� ���������\n";               // ���� � ������ ����� �� ������ ��� �� ������
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
	cout << "������ ��������� \n";
	int xx = _getch();
}

void Admin::Category()
{
	if (Map�ategory.empty())
	{
		Map�ategory.insert(pair<string, map <int, string>>("����������", MapMath));     // �������� ��������� ��� ���������	
		Map�ategory.insert(pair<string, map <int, string>>("������", MapPhys));
		Map�ategory.insert(pair<string, map <int, string>>("�����", MapChem));
		Map�ategory.insert(pair<string, map <int, string>>("������", MapDiff));
		MapMath.insert(pair<int, string>(1, "general.txt"));                            // �������� ��������� ��� ������ �� ����������	
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

	for (auto it = Map�ategory.begin(); it != Map�ategory.end(); ++it)            //����� ��������� �� �����
	{
		if(tst == "All")
		cout << it->first << " : " << endl;

		if (it->first == "����������" && (tst == "����������" || tst == "All"))
		{
			for (auto it = MapMath.begin(); it != MapMath.end(); ++it)
			{
				cout << it->first << " : " << it->second << endl;
				ofstream adout(it->second, ios::app);                        // ������� � ������� ���� � � ������ ��� ���������� �������
				adout.close();
			}
		}
		if (it->first == "������" && (tst == "������" || tst == "All"))
		{
			for (auto it = MapPhys.begin(); it != MapPhys.end(); ++it)
			{
				cout << it->first << " : " << it->second << endl;
				ofstream adout(it->second, ios::app);                        // ������� � ������� ���� � � ������ ��� ���������� �������
				adout.close();
			}
		}
		if (it->first == "�����" && (tst == "�����" || tst == "All"))
		{
			for (auto it = MapChem.begin(); it != MapChem.end(); ++it)
			{
				cout << it->first << " : " << it->second << endl;
				ofstream adout(it->second, ios::app);                        // ������� � ������� ���� � � ������ ��� ���������� �������
				adout.close();
			}
		}
		if (it->first == "������" && (tst == "������" || tst == "All"))
		{
			for (auto it = MapDiff.begin(); it != MapDiff.end(); ++it)
			{
				cout << it->first << " : " << it->second << endl;
				ofstream adout(it->second, ios::app);                        // ������� � ������� ���� � � ������ ��� ���������� �������
				adout.close();
			}
		}
		if (it->first == str_cat && (tst == str_cat || tst == "All"))
		{
			for (auto it = MapOther.begin(); it != MapOther.end(); ++it)
			{
				cout << it->first << " : " << it->second << endl;
				ofstream adout(it->second, ios::app);                        // ������� � ������� ���� � � ������ ��� ���������� �������
				adout.close();
			}
		}
	}
}

void Admin::ShowCategory()
{
	for (auto it = Map�ategory.begin(); it != Map�ategory.end(); ++it)              //����� ��������� �� �����
	{
		cout << it->first << endl;
	}
}

string Admin::FindTest(string choice_category, int choice_test)
{
	string test_name = "No name";
	for (auto it = Map�ategory.begin(); it != Map�ategory.end(); ++it)            //����� ��������� �� �����
	{
		if (it->first == "����������" && choice_category == "����������")
		{
			for (auto it = MapMath.begin(); it != MapMath.end(); ++it)
			{
				if (it->first == choice_test) return it->second;
			}
		}
		if (it->first == "������" && choice_category == "������")
		{
			for (auto it = MapPhys.begin(); it != MapPhys.end(); ++it)
			{
				if (it->first == choice_test) return it->second;
			}
		}
		if (it->first == "�����" && choice_category == "�����")
		{
			for (auto it = MapChem.begin(); it != MapChem.end(); ++it)
			{
				if (it->first == choice_test) return it->second;
			}
		}
		if (it->first == "������" && choice_category == "������")
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
