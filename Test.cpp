#include "Test.h"
#include "Main.h"
#include "Admin.h"

 Admin admin;

void Test::TestChoice()
{
	string way;
	string choice_category;
	int choice_test;
	cout << "������� ��������� �� ������ : \n";	
	admin.Category();
	admin.ShowCategory();
	getline(cin, choice_category);
	cout << "������� ���� �� ��������� : " << choice_category << endl;
		admin.Tests(choice_category);
		cin >> choice_test;
		//admin.FindTest(choice_category, choice_test);
		ifstream fin;
		string file_nm = admin.FindTest(choice_category, choice_test);
		fin.open(file_nm);
		if (!(fin.is_open()))
		{
			cout << "\n������ �������� �����!!! ";
		}
		else
		{
			while (!(fin.eof()))
			{
				way = " ";
				getline(fin, way);
				cout << way << endl;
			}
		}
	system("pause");
	//return false;
}

		