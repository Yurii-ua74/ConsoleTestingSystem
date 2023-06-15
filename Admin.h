#pragma once
#include "Main.h"



class Admin
{
	string  login;             // ����� ������
	string  password;          // ������ ������
	int flag_admin;            // ���� ����� ��� ���
	int y;                     // ���� ����������� ��� ���� � �������
	
public:
	Admin() :login(""), password(""), flag_admin(0), y(0) {};
	Admin(string login, string password, int flag_admin, int y)
		:login(login), password(password), flag_admin(flag_admin), y(y) {};

	void SetFlagAdmin(int a) { flag_admin = a; }          // ���� ����� ��� ���  ����
	void SetY(int a) { y = a; }                           // ���� ����������� ��� ���� � ������� ����
	int GetFlagAdmin() { return flag_admin; }             // ���� ����� ��� ���  �����
	int GetY() { return y; }                              // ���� ����������� ��� ���� � ������� �����
	int registration();                                   // ����� ����������� ������
	int LogIn();                                          // ����� ������������� �� ������ � ������
	void ChangeLogPass();                                 // ����� ����� ������ � ������
	void UserManagement();                                // ����� ���������� ��������������
	void TestManagement();                                // ����� ���������� �������������
	void AddTXT();                                        // ���������� ������ �����
	void EditTXT();                                       // ��������������, ���������� ������
	void Category();
	void Tests(string tst);
	void ShowCategory();
	string FindTest(string choice_category, int choice_test);
	//void ShowTests();
};

//Admin admin;