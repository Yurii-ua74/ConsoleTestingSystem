#include "Main.h"
#include "User.h"

vector <User> uservec;
User user;

void User::CreateUser(int n, int it)           // n == 1 - ���� ����������� ������������� 2 - ���� ������������ ������� � ����� ������  3 - ��� ������� ����������� � �����k ����� �����������
{                                              // it - �������� ��������������� ������������  0 - ��� ������ �������
		cout << "������� ��� ������������\n";	
		cin >> name;
		cout << "������� ������� ������������\n";
		cin >> surname;
		cout << "������� ���� �������� ������������\n";
		cin >> birth;
		cout << "������� ����� �������� ������������\n";
		cin >> phonumb;
		cout << "������� ����� ���������� ������������ :\n";
		cout << "����� - "; cin >> city;
		cout << "����� - "; cin >> street;
		cout << "����� ���� - "; cin >> house;
		cout << "����� �������� - "; cin >> flat;
		cout << "�������� ������� ������ \n";
		us_log = log(1);                       // 1 - ����������  2 - ������������
		this->x = 1;
		us_pas = pas(this->x, 1);
        if (n == 2)                            // ��� ����� ������������ � ����� ������
		uservec.push_back(User(us_log, us_pas, phonumb, name, surname, birth, city, street, house, flat));
		if (n == 3)                            // ��� ������� ����������� � �����k ����� �����������
		{
			//auto iter = uservec.cbegin();   // ����������� �������� ��������� �� ������ �������
			//uservec.emplace(iter + it, User(us_log, us_pas, phonumb, name, surname, birth, city, street, house, flat));  // ������� ������ ������������ (�� ������������ �� �������� ������)

			uservec.at(it) = User(us_log, us_pas, phonumb, name, surname, birth, city, street, house, flat);           //  �������� ������ ������������
		}
	char S;
	cout << "����������� ������ �������������?  \"Y\" or \"N\" : ";
	cin >> S;
	cout << endl;
	if (S == 'Y' || S == 'y' || S == '�' || S == '�')
		user.Show();
	char SS;
	cout << "������ ������ ������������� � ����?  \"Y\" or \"N\" : ";
	cin >> SS;
	if (SS == 'Y' || SS == 'y' || SS == '�' || SS == '�')
	{
		ofstream adout("log_user.txt");                 // �������  ���� 
		if (!(adout.is_open()))                         // �������� �������� ������
		{
			cout << "���� �� ������ ��� ���������\n";   // ���� � ������ ����� �� ������ ��� �� ������
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
	cout << "������� ���  ������������ : ";
	cin >> _name;
	cout << "������� �������  ������������ : ";
	cin >> _surname;
	cout << "������� ����� ��������  ������������ : ";
	cin >> _phonumber;
	for (int i = 0; i < uservec.size(); i++)            // ���������� ��������� ������ � ���������� � ����������
	{		
		if (uservec[i].name == _name &&
			uservec[i].surname == _surname &&
			uservec[i].phonumb == _phonumber)
			return i;                                   // ��� ���������� ���������� ��������
	}
	//for_each(uservec.begin(), uservec.end(), show);   //  �� �����
	return -1;
}

void User::Show()
{
	for (int i = 0; i < uservec.size(); i++)
	{
		cout << "������������ " << "# " << i + 1 << endl;				
		cout << uservec[i].name << endl;
		cout << uservec[i].surname << endl;
		cout << uservec[i].phonumb << endl;
		cout << uservec[i].birth << " �.�." << endl;
		cout << "����� " << uservec[i].city << endl;
		cout << "��. " << uservec[i].street << endl;
		cout << "��� " << uservec[i].house << endl;
		cout << "��. " << uservec[i].flat << endl;
		cout << endl;
	}
	int xx = _getch();
}

void User::ShowOne(int i)
{
		cout << "������������ " << "# " << i + 1 << endl;
		cout << uservec[i].name << endl;
		cout << uservec[i].surname << endl;
		cout << uservec[i].phonumb << endl;
		cout << uservec[i].birth << " �.�." << endl;
		cout << "����� " << uservec[i].city << endl;
		cout << "��. " << uservec[i].street << endl;
		cout << "��� " << uservec[i].house << endl;
		cout << "��. " << uservec[i].flat << endl;
	int xx = _getch();
}

void User::RegistrUser()
{
	user.CreateUser(2, 0);
}

bool User::LogInUser()                              // ���� ������������ � �������
{
	string temp_log;
	string temp_pas;	
	ifstream adin("log_user.txt");                  // ������� ���� ��� ������
	if (!adin.is_open())
	{
		cout << "���� �� ������ ��� ���������\n";   // ���� ���� �� ������ ��� ���������
	}
	else
	{
		temp_log = log(2);
		temp_pas = pas(0,2);
		string ch;
		int i = 0;
		int j = 0;
		// ��������� � ����� 	
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
						cout << "����� ���������� �� ������������ " << this->name << " " << this->surname << endl;
						adin.close();
						return true;
					}
					else cout << "�� ��������� ������ ������\n";
					adin.close();
					return false;
				}
				else cout << "������������ � ����� ������� �� ����������������\n";                              //cout << "������������ � ������ " << temp_log << "�� �������!!! ";
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
	if (uservec.size() == 0) { cout << "�� ���������������� �������� ������������ \n"; int xx = _getch(); }
	else
	{
		char S;
		int it = FindUser();
		auto iter = uservec.cbegin();                      // ��������� �� ������ �������
		uservec.erase(iter + it);                          // ������� �������
		cout << "����������� �������?  \"Y\" or \"N\" : ";
		cin >> S;
		if (S == 'Y' || S == 'y' || S == '�' || S == '�')
			user.Show();
	}
}

void User::ModifyUser()
{
	if (uservec.size() == 0) { cout << "�� ���������������� �������� ������������ \n"; int xx = _getch(); }
	else
	{
		int it = FindUser();
		user.ShowOne(it);
		user.CreateUser(3, it);		
	}
}
