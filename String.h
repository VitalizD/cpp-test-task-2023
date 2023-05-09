#pragma once

#include<ostream>

class String
{
public:
	String(); // ����������� �� ���������
	String(const char* c_str); // ����������� ��� ������������������ ��������
	String(const String& other); // ����������� �����������
	String(String&& other) throw(); // ����������� �����������
	~String(); // ����������
	char* c_str() const; // C-������
	size_t length() const; // ����� ������
	String& operator=(const String& other); // �������� ������������ � ������������
	String& operator=(String&& other) throw(); // �������� ������������ � ������������
	String& operator=(const char* c_str); // �������� ������������ � ������������ (C-style)
	String& operator+=(const String& other); // �������� ����������
	String& operator+=(const char* c_str); // �������� ���������� (C-style)
	friend String operator+(const String& lvalue, const String& rvalue); // �������� ��������
	friend String operator+(const String& lvalue, const char* rvalue); // �������� �������� (C-style)
	friend std::ostream& operator<<(std::ostream& os, const String& str); // �������� ������
	char operator[](unsigned index) const; // �������� ��������������
	bool operator<(const String& other) const; // �������� "������"
	bool operator>(const String& other) const; // �������� "������"

private:
	char* data;
	size_t size;
};