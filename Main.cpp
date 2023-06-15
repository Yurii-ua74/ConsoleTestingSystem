//����������� ������������������� ������� ������������.

//� ������� ������ ���� ����������� 2 ������:
 //�������������;
 //�����������.
#include "Main.h"

void ChangeFile(string& s, string l, string p) // ������� �������� �����, ����� � ������
{
	ofstream adout(s);                         // �������  ���� ��� ������ ����������
	if (!adout.is_open())
	{
		cout << "���� �� ������ ��� ���������\n";
	}
	else
	{
		adout << l << endl;              // ������ � ���� ������ ������
		adout << p << endl;              // ������ � ���� ������ ������
	}
	adout.close();
}

string log(int k)                              // ����������� ��� ���� ������
{
	string log;
	cout << "������� ����� \n";
	do
	{
		getline(cin, log);
	} while (log == "");
	if(k == 1)  return KeyLock(log);           //log + key;    1 - ����������  
	if(k == 2)  return log;
	return "error";
}

string pas(int fl, int k)                      // ����������� ��� ���� ������ (� ������� ������� ���� ����������� ������ ��� ���� �������������)
{
	int cnt = 0;                        // ����� ���-�� �������� � ������
	int num = 0;                        // ���-�� ����
	int sml = 0;                        // ���-�� ��� ����
	int grn = 0;                        // ���-�� ��� ����
	string pas1;                        // ���� ������ ����� ������ ������ ��� �����������
	string pas2;                        // ���� ������ ����� ������ ������ ��� �����������
	do
	{
		cout << "������� ������\n(�� ������ 5 �������� ��������� �� ���� ���������, ������� � ����) \n";
		do
		{
			getline(cin, pas1);
		} while (pas1 == "");
		// ������� string �� ������� � ������� �� ������������ ������ �����������
		for (int i = 0; i != pas1.size(); i++)
		{
			if (pas1.at(i) > 47 && pas1.at(i) < 58) num++;     // ���� �� � ������ �����
			if (pas1.at(i) > 64 && pas1.at(i) < 91) grn++;     // ���� �� ������� �����
			if (pas1.at(i) > 96 && pas1.at(i) < 123) sml++;    // ���� �� ��������� �����
		}
		cnt = num + grn + sml;                                 // ������� �������� � ������
	} while (cnt < 5 && num == 0 && grn == 0 && sml == 0);
	if (fl == 1)                                               // ���� ���� ��������� �� �� ���� � ��������� ������� (�.�. � ���� ������ ����� 1) 
	{                                                          // fl == 1 - ����������� / 0 - ���� � �������
		int equ = 0;                                           // ���������� ��������� �������
		do
		{
			if (cnt >= 5 && num > 0 && grn > 0 && sml > 0)
			{
				cout << "������� ������ ��� �������������\n";
				getline(cin, pas2);
			}
			equ = pas1.compare(pas2);                          // ����������� ������ ���������� ������
			if (equ == 0)
				cout << "������ �����������\n";
			else cout << "������ �� ���������\n";
		} while (equ != 0);
	}
	if (k == 1)  return KeyLock(pas1);                         //  1 - ����������  
	if (k == 2)  return pas1;
	return "error";
}

string Key(string str)                                         // ��� ������������ ������
{
	for (int i = 0; i != str.size(); i++)
	{
		str.at(i) = str.at(i) - key;
	}
	return str;
}

string KeyLock(string str)                                    // ��� ���������� ������
{
	for (int i = 0; i != str.size(); i++)
	{
		str.at(i) = str.at(i) + key;
	}
	return str;
}